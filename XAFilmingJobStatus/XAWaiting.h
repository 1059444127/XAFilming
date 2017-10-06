#pragma once
#include "XAFilmingJobStatusBase.h"
class XAWaiting :
    public XAFilmingJobStatusBase
{
public:
    virtual bool Pause(IXAFilmingJob* const job);
    virtual std::string ToString() const;
    
};
