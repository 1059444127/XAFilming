#pragma once
#include "XAFilmingJobStatusBase.h"

class XAPrinting :
    public XAFilmingJobStatusBase
{
public:
   virtual std::string ToString() const ;
    virtual void Complete(IXAFilmingJob* const job);
    virtual void Fail(IXAFilmingJob* const job);
};

