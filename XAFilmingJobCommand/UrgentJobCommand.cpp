#include "UrgentJobCommand.h"
#include "XAFilmingLogger.h"

UrgentJobCommand::UrgentJobCommand(IXAFilmingJobDispatch* jobDispatcher) : _jobDispatcher(jobDispatcher)
{
}

void UrgentJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Urgent Job Commmand Excuting" << LOG_END;
    _jobDispatcher->UrgentJobs(IDs);
}
