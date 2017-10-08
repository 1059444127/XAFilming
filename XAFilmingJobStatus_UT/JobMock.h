#pragma once
#include "XAFilmingJobBase.h"

class JobMock :
    public XAFilmingJobBase
{
public:
    virtual void TopPriority() {}
    virtual int GetPriority() {return 0;}
    virtual void ResetPriority() {}
    virtual std::string GetProgress() {return std::string();}
    JobMock();

    virtual int GetJobID();
};

