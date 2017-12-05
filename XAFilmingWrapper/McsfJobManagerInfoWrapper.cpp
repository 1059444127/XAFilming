#include "McsfJobManagerInfoWrapper.h"
#include "McsfJobManagerInfo/mcsf_jobmanager_info_wrapper.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"
#include <McsfNetBase/mcsf_communication_node_name.h>
#include <McsfNetBase/mcsf_netbase_command_context.h>
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>
#include <XAFilmingConst.h>
#include <XAConfig.h>

using namespace Mcsf::JobManager;
using namespace MCSF_NAMESPACE_FOR_XA;


vector<int> GetJobIDsFrom(const string& serializedJobManagerInfo)
{
	LOG_INFO_XA_FILMING << "Get Job IDs From Serialized JobManagerInfo" << LOG_END;

	JobManagerInfos job_manager_infos;
	job_manager_infos.ParseFromString(serializedJobManagerInfo);

	vector<int> jobIDs;
	for(int i=0; i<job_manager_infos.infojobmanager_size(); i++)
	{
		auto jobManagerInfo = job_manager_infos.mutable_infojobmanager(i);
		string jobItemID = jobManagerInfo->jobitemid();
		int jobID = string_to_int(jobItemID);
		jobIDs.push_back(jobID);
	}
	return jobIDs;
}

JobManagerItemStatus ConvertFrom(XAFilmingJobStatusEnum job_status)
{
	switch (job_status)
	{
	case XAFilmingJobStatusEnum::Done : return JobManagerItemStatus::Completed;
	case XAFilmingJobStatusEnum::Failed : return JobManagerItemStatus::Failed;
	case XAFilmingJobStatusEnum::Paused : return JobManagerItemStatus::Paused;
	case XAFilmingJobStatusEnum::Printing : return JobManagerItemStatus::Inprocess;
	case XAFilmingJobStatusEnum::Waiting : return JobManagerItemStatus::Waiting;
	}

	LOG_INFO_XA_FILMING << "Unsupported job status [" << job_status << "]" << LOG_END;
	return JobManagerItemStatus::Completed;
}

void Translate(XAFilmingJobBase* pJob, McsfJobManagerInfo& job_manager_info)
{
	job_manager_info.SetJobitemid(int_to_string(pJob->GetJobID()));
	string sProgress = int_to_string(double_to_percentage(pJob->GetProgress()));
	job_manager_info.SetProgress(sProgress);
	job_manager_info.SetTotalFiles(pJob->GetTotal());
	job_manager_info.SetFinishedFiles(pJob->GetFinished());
	job_manager_info.SetJobitemstatus(ConvertFrom(pJob->GetJobStatus()->GetStatusPriority()));	

	auto jobMetaData = pJob->GetMetaData();
	job_manager_info.SetPatientid(jobMetaData->GetPatientID());
	job_manager_info.SetPatientname(jobMetaData->GetPatientName());
	job_manager_info.SetDatetime(jobMetaData->GetJobCreateTime());

	auto printer = XAConfig::Instance()->GetPrinterConfig();
	job_manager_info.SetDestinationname(printer->GetAE());
	//TODO:  ß∞‹–≈œ¢
}

string SerializeFrom(const vector<XAFilmingJobBase*>& jobs)
{
	LOG_INFO_XA_FILMING << "Serialize job collection" << LOG_END;

	vector<McsfJobManagerInfo> job_manager_infos;
	
	for(auto iter = jobs.begin(); iter != jobs.end(); iter++)
	{
		McsfJobManagerInfo job_manager_info;
		Translate(*iter, job_manager_info);
		job_manager_infos.push_back(job_manager_info);
	}

	McsfJobManagerInfoWrapper job_manager_info_wrapper;
	job_manager_info_wrapper.SetJobModality(Film);
	job_manager_info_wrapper.AddJobManagerInfos(job_manager_infos);
	
	return job_manager_info_wrapper.Serialize();
}

string GetJobManagerCommunicationNodeName()
{
	return CommunicationNodeName::CreateCommunicationProxyName(XA_FILMING_JOB_MANAGER, XA_FILMING_FRONT_END);
}

void PushJobProgressToJobManager(const vector<XAFilmingJobBase*>& jobs, ICommunicationProxy* pProxy)
{
	CommandContext command_context;
	command_context.sSerializeObject = SerializeFrom(jobs);
	command_context.iCommandId = ToMainFrameCmd;
	command_context.sReceiver =  GetJobManagerCommunicationNodeName(); 
	
	pProxy->AsyncSendCommand(&command_context);
}

