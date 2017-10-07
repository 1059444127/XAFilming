#include "DeleteJobCommand.h"
#include "XAFilmingLogger.h"


void DeleteJobCommand::Excute(const std::vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Delete Job Command excuting" << LOG_END;
    _jobDispatcher->DeleteJobs(IDs);
}
