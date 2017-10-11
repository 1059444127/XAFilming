#include "McsfJobManagerInfoWrapper.h"
#include "McsfJobManagerInfo/mcsf_jobmanager_info_wrapper.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"

using namespace Mcsf::JobManager;

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
	job_manager_info.SetProgress(pJob->GetProgress());
	job_manager_info.SetJobitemstatus(ConvertFrom(pJob->GetJobStatus()->GetStatusPriority()));	
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

