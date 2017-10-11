#include "XAFilmingJobStatusBase.h"
#include "XAFilmingJobBase.h"
#include "XAFilmingLogger.h"

void XAFilmingJobStatusBase::Continue(XAFilmingJobBase*  const job)
{
    LOG_WARN_XA_FILMING << "Continue job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Pause(XAFilmingJobBase*  const job)
{
    LOG_WARN_XA_FILMING << "Pause job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Restart(XAFilmingJobBase*  const job)
{
    LOG_WARN_XA_FILMING << "Restart job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Print(XAFilmingJobBase* const job)
{
    LOG_WARN_XA_FILMING << "Film job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Complete(XAFilmingJobBase* const job)
{
    LOG_WARN_XA_FILMING << "Complete job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Fail(XAFilmingJobBase* const job)
{
    LOG_WARN_XA_FILMING << "Set Failed flag of job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

void XAFilmingJobStatusBase::Urgent(XAFilmingJobBase* const job)
{
    LOG_WARN_XA_FILMING << "Urgent job [ " << job->GetJobID() << "] with Status [" << job->GetJobStatus()->ToString() << "]" << LOG_END;
    LOG_WARN_XA_FILMING << "Job Status: " << ToString() << LOG_END;
}

bool XAFilmingJobStatusBase::IsAtomic()
{
    return false;
}

