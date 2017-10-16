#include "McsfJobManagerInfo/mcsf_jobmanager_info.pb.h"
#include "..\..\..\..\IAS\XParameters\Contract\CommunicationCommandID.h"
#include <XAFilmingMacro.h>
#include "XACommandID.h"
using namespace MCSF_NAMESPACE_FOR_XA;

std::vector<int> GetXACommandIDs()
{
	std::vector<int> commandIDs;

	commandIDs.push_back(JobManager::FromMainFrameContinueCmd);
	commandIDs.push_back(JobManager::FromMainFrameDeleteCmd);
	commandIDs.push_back(JobManager::FromMainFramePauseCmd);
	commandIDs.push_back(JobManager::FromMainFrameRefreshCmd);
	commandIDs.push_back(JobManager::FromMainFrameRestartCmd);
	commandIDs.push_back(JobManager::FromMainFrameStopCmd);
	commandIDs.push_back(JobManager::FromMainFrameUrgentCmd);

	commandIDs.push_back(COMMAND_ID_FILMING);
	commandIDs.push_back(COMMAND_ID_FILMING_DATAHEADER);

	return commandIDs;
}