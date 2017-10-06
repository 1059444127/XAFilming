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
private:
    XAFilmingJobStatusBase* _status;
};