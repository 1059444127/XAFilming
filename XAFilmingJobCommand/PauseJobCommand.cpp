#include "PauseJobCommand.h"
#include "XAFilmingLogger.h"

void PauseJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Pause job command executing" << LOG_END;
    _jobDispatcher->PauseJobs(IDs);
}
