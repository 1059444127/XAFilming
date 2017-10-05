#include "JobMock.h"
#include "XAFilmingMacro.h"
#include "XAFilmingJobStatusFactory.h"


JobMock::JobMock()
{
    _status = XAFilmingJobStatusFactory::Instance()->CreateJobStatus();
}


JobMock::~JobMock()
{
    SAFE_DELETE_ELEMENT(_status);
}

const XAFilmingJobStatusBase* JobMock::GetJobStatus()
{
    return _status;
}

void JobMock::SetJobStatus(const XAFilmingJobStatusBase* jobStatus)
{
    if(_status == jobStatus) return;
    SAFE_DELETE_ELEMENT(_status);
    _status = jobStatus;
}


