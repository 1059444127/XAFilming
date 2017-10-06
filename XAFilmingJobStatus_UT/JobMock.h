#pragma once
#include "XAFilmingJobBase.h"

class JobMock :
    public XAFilmingJobBase
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

