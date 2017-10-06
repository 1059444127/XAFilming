#pragma once
#include "IXAFilmingJob.h"

class JobMock :
    public IXAFilmingJob
{
public:
    JobMock();
    ~JobMock();

    virtual int GetJobID();
    virtual XAFilmingJobStatusBase* GetJobStatus();
    virtual void SetJobStatus(XAFilmingJobStatusBase* jobStatus);

private:
    XAFilmingJobStatusBase* _status;
};

