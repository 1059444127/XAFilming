#pragma once
#include <XAFilmingJobStatusBase.h>

class XAPaused :
    public XAFilmingJobStatusBase
{
public:
    virtual void Continue(IXAFilmingJob* const job) ;
    virtual std::string ToString() const ;
};

