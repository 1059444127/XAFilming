#include "XAWaiting.h"
#include "XAFilmingLogger.h"
#include "IXAFilmingJob.h"
#include "XAPaused.h"
#include "XAFilmingConst.h"


void XAWaiting::Pause(IXAFilmingJob* const job)
{
    LOG_INFO_XA_FILMING << "Pause job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XAPaused());
}

std::string XAWaiting::ToString() const
{
    return XA_Filming_Job_Waiting;
}
