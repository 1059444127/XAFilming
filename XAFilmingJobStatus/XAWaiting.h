#pragma once
#include "XAFilmingJobStatusBase.h"
class XAWaiting :
    public XAFilmingJobStatusBase
{
public:
    virtual void Pause(XAFilmingJobBase* const job);
    virtual void Print(XAFilmingJobBase* const job);
    virtual std::string ToString() const;

    virtual XAFilmingJobStatusEnum GetStatusPriority();
};
