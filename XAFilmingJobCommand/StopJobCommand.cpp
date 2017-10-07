#include "StopJobCommand.h"
#include "XAFilmingLogger.h"


void StopJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Stop Job Command Excuting" << LOG_END;
    _jobDispatcher->PauseJobs(IDs);
}
