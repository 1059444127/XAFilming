#pragma once
#include "XAFilmingJobBase.h"

class JobMock :
    public XAFilmingJobBase
{
public:
    JobMock();

    virtual int GetJobID();
};

