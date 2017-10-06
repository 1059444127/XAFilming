#pragma once
#include "XAFilmingJobExportMacro.h"
#include "XAFilmingJobBase.h"
#include "XAFilmingMacro.h"

class XA_FilmingJob_Export XAFilmingJobFactory
{
public:
    static XAFilmingJobFactory* Instance();
    XAFilmingJobBase* CreateJob();
    ~XAFilmingJobFactory() {SAFE_DELETE_ELEMENT(_instance);}

private:
    static XAFilmingJobFactory* _instance;
    static int _maxJobID;
    XAFilmingJobFactory() {};
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobFactory)
};

