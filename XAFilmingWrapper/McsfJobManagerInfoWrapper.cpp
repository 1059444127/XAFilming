#include "McsfJobManagerInfoWrapper.h"
#include "McsfJobManagerInfo/mcsf_jobmanager_info.pb.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"

vector<int> GetJobIDsFrom(const string& serializedJobManagerInfo)
{
	LOG_INFO_XA_FILMING << "Get Job IDs From Serialized JobManagerInfo" << endl;

	Mcsf::JobManager::JobManagerInfos job_manager_infos;
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
