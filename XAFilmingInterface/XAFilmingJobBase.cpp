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
