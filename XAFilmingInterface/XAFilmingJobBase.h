#pragma once

#include "XAFilmingJobStatusBase.h"
#include "IXAFilmingProxy.h"
#include "IProgress.h"
#include "IPriority.h"

class XA_FilmingInterface_Export XAFilmingJobBase : public IXAFilmingProxy, public IProgress, public IPriority
{
public:
    XAFilmingJobBase(XAFilmingJobStatusBase* status);
    virtual int GetJobID() = 0;
    virtual XAFilmingJobStatusBase* GetJobStatus();
    virtual void SetJobStatus(XAFilmingJobStatusBase* jobStatus);
    virtual ~XAFilmingJobBase();

    virtual void Complete();
    virtual void Continue();
    virtual void Fail();
    virtual void Pause();
    virtual void Print();
    virtual void Restart();
    virtual void Urgent();
    virtual bool CanCancel();

    //TODO: interface inheritance

private:
    XAFilmingJobStatusBase* _status;
};
