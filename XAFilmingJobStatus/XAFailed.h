#pragma once
#include <XAFilmingJobStatusBase.h>

class XAFailed :
    public XAFilmingJobStatusBase
{
public:
    virtual bool Restart(IXAFilmingJob* const job);
    virtual std::string ToString() const;
};

