#pragma once
#include <XAFilmingJobStatusBase.h>

class XAFailed :
    public XAFilmingJobStatusBase
{
public:
    virtual void Restart(XAFilmingJobBase* const job);
    virtual std::string ToString() const;
    virtual XAFilmingJobStatusEnum GetStatusPriority();
};

