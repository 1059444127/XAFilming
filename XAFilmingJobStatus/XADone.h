#pragma once
#include <XAFilmingJobStatusBase.h>

class XADone :
    public XAFilmingJobStatusBase
{
public:
    virtual void Restart(XAFilmingJobBase* const job);
    virtual std::string ToString() const;
    virtual XAFilmingJobStatusEnum GetStatusPriority();
};

