#pragma once
#include "XAFilmingJobStatusBase.h"

class XAPrinting :
    public XAFilmingJobStatusBase
{
public:
   virtual std::string ToString() const ;
    virtual void Complete(XAFilmingJobBase* const job);
    virtual void Fail(XAFilmingJobBase* const job);
    virtual XAFilmingJobStatusEnum GetStatusPriority();
    virtual bool IsAtomic();
};

