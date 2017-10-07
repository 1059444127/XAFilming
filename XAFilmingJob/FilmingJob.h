#pragma once
#include "XAFilmingJobBase.h"
#include "../XAFilmingCommon/XAFilmingMacro.h"

class FilmingJob :
    public XAFilmingJobBase
{
public:
    FilmingJob(int ID);
    virtual int GetJobID();
    virtual void ResetPriority();
    virtual int GetPriority();
    virtual void TopPriority();
private:
    static int MaxPriority;
    int _iID;
    int _iPriority;
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(FilmingJob);
};

