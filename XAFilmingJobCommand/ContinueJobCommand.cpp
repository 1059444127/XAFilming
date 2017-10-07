#include "ContinueJobCommand.h"
#include "XAFilmingLogger.h"

ContinueJobCommand::ContinueJobCommand(IXAFilmingJobDispatch* jobDispatcher) : _jobDispatcher(jobDispatcher)
{
}

void ContinueJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Continue job command excuting" << LOG_END;
    _jobDispatcher->ContinueJobs(IDs);
}
