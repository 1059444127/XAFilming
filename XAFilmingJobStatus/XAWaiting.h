#pragma once
#include "XAFilmingJobStatusBase.h"
class XAWaiting :
    public XAFilmingJobStatusBase
{
public:
    virtual void Pause(IXAFilmingJob* const job);
    virtual void Print(IXAFilmingJob* const job);
    virtual std::string ToString() const;
    
};
