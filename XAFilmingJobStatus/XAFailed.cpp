#include "XAFailed.h"
#include "XAFilmingLogger.h"
#include "XAFilmingJobBase.h"
#include "XAWaiting.h"
#include "XAFilmingConst.h"

void XAFailed::Restart(XAFilmingJobBase* const job)
{
    LOG_INFO_XA_FILMING << "Restart job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_INFO_XA_FILMING << "Job Status: " << ToString() << LOG_END;

    job->SetJobStatus(new XAWaiting());
}

std::string XAFailed::ToString() const
{
    return XA_Filming_Job_Failed;
}

XAFilmingJobStatusEnum XAFailed::GetStatusPriority()
{
    return Failed;
}
