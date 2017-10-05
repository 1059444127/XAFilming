#pragma once

#include "XAFilmingJobStatusBase.h"

class IXAFilmingJob
{
public:
    virtual int GetJobID() = 0;
    virtual const XAFilmingJobStatusBase* GetJobStatus() = 0;
    virtual void SetJobStatus(const XAFilmingJobStatusBase* jobStatus) = 0;
};