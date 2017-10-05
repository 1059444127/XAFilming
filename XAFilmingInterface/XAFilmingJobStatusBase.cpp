#include "XAFilmingJobStatusBase.h"
#include "IXAFilmingJob.h"
#include "XAFilmingLogger.h"

void XAFilmingJobStatusBase::Continue(IXAFilmingJob*  const job)
{
    LOG_WARN_XA_FILMING << "Continue job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
}

void XAFilmingJobStatusBase::Pause(IXAFilmingJob*  const job)
{
    LOG_WARN_XA_FILMING << "Pause job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
}

void XAFilmingJobStatusBase::Restart(IXAFilmingJob*  const job)
{
    LOG_WARN_XA_FILMING << "Restart job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
}