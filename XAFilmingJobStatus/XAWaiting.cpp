#include "XAWaiting.h"
#include "XAFilmingLogger.h"
#include "XAFilmingJobBase.h"
#include "XAPaused.h"
#include "XAFilmingConst.h"
#include "XAPrinting.h"


void XAWaiting::Pause(XAFilmingJobBase* const job)
{
    LOG_INFO_XA_FILMING << "Pause job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XAPaused());
}

void XAWaiting::Print(XAFilmingJobBase* const job)
{
    LOG_INFO_XA_FILMING << "Print job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XAPrinting());
}

std::string XAWaiting::ToString() const
{
    return XA_Filming_Job_Waiting;
}
