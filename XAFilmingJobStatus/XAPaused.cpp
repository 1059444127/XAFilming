#include "XAPaused.h"
#include "XAFilmingLogger.h"
#include "IXAFilmingJob.h"
#include "XAWaiting.h"


void XAPaused::Continue(IXAFilmingJob* const job)
{
    LOG_INFO_XA_FILMING << "Continue job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;
    
    job->SetJobStatus(new XAWaiting());
}

std::string XAPaused::ToString() const
{
    return "Paused";
}
