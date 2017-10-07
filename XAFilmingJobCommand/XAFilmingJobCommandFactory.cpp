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
    _filmingCommandDictionary[1] = new ContinueJobCommand();
    _filmingCommandDictionary[2] = new DeleteJobCommand();
    _filmingCommandDictionary[3] = new PauseJobCommand();
    _filmingCommandDictionary[4] = new RefreshJobCommand();
    _filmingCommandDictionary[5] = new RestartJobCommand();
    _filmingCommandDictionary[6] = new StopJobCommand();
    _filmingCommandDictionary[7] = new UrgentJobCommand();
}
