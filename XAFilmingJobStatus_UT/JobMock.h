#pragma once
#include "IXAFilmingJob.h"

class JobMock :
    public IXAFilmingJob
{
public:
    JobMock();
    ~JobMock();

    virtual int GetJobID();
    virtual const XAFilmingJobStatusBase* GetJobStatus();
    virtual void SetJobStatus(const XAFilmingJobStatusBase* jobStatus);

private:
    const XAFilmingJobStatusBase* _status;
};

