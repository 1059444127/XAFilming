#pragma once

#include "XAFilmingJobStatusBase.h"

class IXAFilmingJob
{
public:
    virtual int GetJobID() = 0;
    virtual XAFilmingJobStatusBase GetJobStatus() = 0;
};