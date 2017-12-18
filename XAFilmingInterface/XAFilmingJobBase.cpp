#include "XAFilmingJobBase.h"
#include "XAFilmingLogger.h"
#include "XAFilmingMacro.h"
#include "XAFilmingSerializer.h"

XAFilmingJobBase::XAFilmingJobBase(XAFilmingJobStatusBase* status) : _status(status)
{
	_metaData = new NullFilmingJobMetaData();
}

XAFilmingJobStatusBase* XAFilmingJobBase::GetJobStatus()
{
    return _status;
}

IFilmingJobMetaData* XAFilmingJobBase::GetMetaData()
{
	return _metaData;
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
	SAFE_DELETE_ELEMENT(_metaData);
}

void XAFilmingJobBase::Complete()
{
    LOG_INFO_XA_FILMING << "Complete job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Complete(this);
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

void XAFilmingJobBase::Film()
{
    LOG_INFO_XA_FILMING << "Film job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Print(this);
}

void XAFilmingJobBase::Restart()
{
    LOG_INFO_XA_FILMING << "Restart job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Restart(this);
}

void XAFilmingJobBase::Urgent()
{
    LOG_INFO_XA_FILMING << "Urgent job [" << GetJobID() << "] with status [" << GetJobStatus()->ToString() << "]" << LOG_END;
    _status->Urgent(this);
}

bool XAFilmingJobBase::CanCancel()
{
    return !_status->IsAtomic();
}

void XAFilmingJobBase::SetLastResult(const std::string& result)
{
	LOG_INFO_XA_FILMING << "Last Result: " << result << LOG_END;
	_lastResult = result;

	bool bStatus = string_to_bool(result);
	bStatus ? Complete() : Fail();
}
