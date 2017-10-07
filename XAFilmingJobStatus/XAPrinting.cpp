#include "XAPrinting.h"
#include "XAFilmingConst.h"
#include "XAFilmingLogger.h"
#include "XAFilmingJobBase.h"
#include "XADone.h"
#include "XAFailed.h"


std::string XAPrinting::ToString() const
{
    return XA_Filming_Job_Printing;
}

void XAPrinting::Complete(XAFilmingJobBase* const job)
{
    LOG_INFO_XA_FILMING << "Complete job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XADone());

    job->ResetPriority();
}

void XAPrinting::Fail(XAFilmingJobBase* const job)
{
    LOG_INFO_XA_FILMING << "Set Failed flag of job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XAFailed());
}

XAFilmingJobStatusEnum XAPrinting::GetStatusPriority()
{
    return Printing;
}

bool XAPrinting::IsAtomic()
{
    return true;
}
