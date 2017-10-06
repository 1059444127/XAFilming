#include "XAFilmingJobBase.h"
#include "XAFilmingLogger.h"
#include "XAFilmingMacro.h"

XAFilmingJobBase::XAFilmingJobBase(XAFilmingJobStatusBase* status) : _status(status)
{
}

XAFilmingJobStatusBase* XAFilmingJobBase::GetJobStatus()
{
    return _status;
}

void XAFilmingJobBase::SetJobStatus(XAFilmingJobStatusBase* jobStatus)
{
    LOG_INFO_XA_FILMING << "Set job [" << GetJobID() << "] with Status [" << GetJobStatus()->ToString() << "] to Status [" << jobStatus->ToString() << "]" << LOG_END;
    if(_status == jobStatus) return;

    SAFE_DELETE_ELEMENT(_status);
    _status = jobStatus;
}

XAFilmingJobBase::~XAFilmingJobBase()
{
    SAFE_DELETE_ELEMENT(_status);
}

void XAFilmingJobBase::Complete()
{
    LOG_INFO_XA_FILMING << "Complete job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
}

void XAFilmingJobBase::Continue()
{
    LOG_INFO_XA_FILMING << "Continue job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Continue(this);
}

void XAFilmingJobBase::Fail()
{
    LOG_INFO_XA_FILMING << "Set Failed flag for job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Fail(this);
}

void XAFilmingJobBase::Pause()
{
    LOG_INFO_XA_FILMING << "Pause job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Pause(this);
}

void XAFilmingJobBase::Print()
{
    LOG_INFO_XA_FILMING << "Print job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Print(this);
}

void XAFilmingJobBase::Restart()
{
    LOG_INFO_XA_FILMING << "Restart job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Restart(this);
}
