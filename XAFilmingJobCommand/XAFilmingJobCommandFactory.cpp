//#include <boost/thread/mutex.hpp>

#include "XAFilmingJobCommandFactory.h"
#include "XAFilmingLogger.h"
#include "ContinueJobCommand.h"
#include "DeleteJobCommand.h"
#include "PauseJobCommand.h"
#include "RefreshJobCommand.h"
#include "RestartJobCommand.h"
#include "StopJobCommand.h"
#include "UrgentJobCommand.h"
#include <McsfJobManagerInfo/mcsf_jobmanager_info.pb.h>
#include "../../../XParameters/Contract/CommunicationCommandID.h"
#include "FilmDicomFileCommand.h"

XAFilmingJobCommandFactory* XAFilmingJobCommandFactory::_pInstance = new XAFilmingJobCommandFactory();

//static boost::mutex lock_mutex;

XAFilmingJobCommandFactory* XAFilmingJobCommandFactory::GetInstance()
{
	//if(nullptr == _pInstance)
	//{
	//	boost::mutex::scoped_lock singleton_lock(lock_mutex);
		//if(nullptr == _pInstance)
		//{
			//_pInstance = new XAFilmingJobCommandFactory();			
		//}
	//}
	return _pInstance;
}

IXAFilmingCommand* XAFilmingJobCommandFactory::GetFilmingCommand(int commandID, IXAFilmingJobDispatch* jobDispatcher)
{
    LOG_INFO_XA_FILMING << "Getting Command [" << commandID << "]" << LOG_END;
    auto jobCommand = _filmingCommandDictionary[commandID];
    jobCommand->SetJobDispatcher(jobDispatcher);

    return jobCommand;
}

XAFilmingJobCommandFactory::~XAFilmingJobCommandFactory()
{
    for (auto iter = _filmingCommandDictionary.begin(); iter != _filmingCommandDictionary.end(); iter++)
    {
        auto filmingCommand = iter->second;
        SAFE_DELETE_ELEMENT(filmingCommand);
    }
    SAFE_DELETE_ELEMENT(_pInstance)
}

XAFilmingJobCommandFactory::XAFilmingJobCommandFactory():_filmingCommandDictionary()
{
    //TODO: Map Command ID & Command
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameContinueCmd] = new ContinueJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameDeleteCmd] = new DeleteJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFramePauseCmd] = new PauseJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameRefreshCmd] = new RefreshJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameRestartCmd] = new RestartJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameStopCmd] = new StopJobCommand();
    _filmingCommandDictionary[Mcsf::JobManager::JobManagerCommunicationID::FromMainFrameUrgentCmd] = new UrgentJobCommand();

	_filmingCommandDictionary[COMMUNICATION_COMMAND_ID::COMMAND_ID_FILMING] = new FilmDicomFileCommand();
	_filmingCommandDictionary[COMMUNICATION_COMMAND_ID::COMMAND_ID_FILMING_DATAHEADER] = nullptr;
}
