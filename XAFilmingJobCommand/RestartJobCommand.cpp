#include "RestartJobCommand.h"
#include "XAFilmingLogger.h"

RestartJobCommand::RestartJobCommand(IXAFilmingJobDispatch* jobDispatcher) : _jobDispatcher(jobDispatcher)
{
}

void RestartJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Restart Job Command Excuting" << LOG_END;
    _jobDispatcher->RestartJobs(IDs);
}
