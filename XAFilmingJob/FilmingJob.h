#pragma once
#include "XAFilmingJobBase.h"
#include "../XAFilmingCommon/XAFilmingMacro.h"

class FilmingJob :
    public XAFilmingJobBase
{
public:
    FilmingJob(int ID);
    virtual int GetJobID();
private:
    int _iID;
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(FilmingJob);
};

