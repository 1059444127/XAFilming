#pragma once
#include <XAFilmingJobStatusBase.h>

class XADone :
    public XAFilmingJobStatusBase
{
public:
    virtual void Restart(IXAFilmingJob* const job);
    virtual std::string ToString() const;
};

