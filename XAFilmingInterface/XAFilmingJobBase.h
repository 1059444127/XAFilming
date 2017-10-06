#pragma once

#include "XAFilmingJobStatusBase.h"

class XA_FilmingInterface_Export XAFilmingJobBase
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

private:
    XAFilmingJobStatusBase* _status;
};