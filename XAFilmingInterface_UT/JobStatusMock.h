#pragma once
#include <XAFilmingJobStatusBase.h>

class JobStatusMock :
    public XAFilmingJobStatusBase
{
public:
    JobStatusMock(XAFilmingJobStatusEnum xa_filming_job_status_enum)
        : _status(xa_filming_job_status_enum)
    {
    }

    virtual std::string ToString() const {return std::string();};
    virtual XAFilmingJobStatusEnum GetStatusPriority() {return _status;}
private:
    XAFilmingJobStatusEnum _status;
};

