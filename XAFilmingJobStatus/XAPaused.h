#pragma once
#include <XAFilmingJobStatusBase.h>

class XAPaused :
    public XAFilmingJobStatusBase
{
public:
    virtual bool Continue(IXAFilmingJob* const job) ;
    virtual std::string ToString() const ;
};

