#include "StopJobCommand.h"
#include "XAFilmingLogger.h"


StopJobCommand::StopJobCommand(IXAFilmingJobDispatch* jobDispatcher) : _jobDispatcher(jobDispatcher)
{
}

void StopJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Stop Job Command Excuting" << LOG_END;
    _jobDispatcher->PauseJobs(IDs);
}
