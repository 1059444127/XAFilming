#pragma once

#include "XAFilmingJobStatusExportMacro.h"
#include "XAFilmingMacro.h"
#include "XAFilmingJobStatusBase.h"

class XA_FilmingJobStatus_Export  XAFilmingJobStatusFactory
{
public:
    static XAFilmingJobStatusFactory* Instance();
    XAFilmingJobStatusBase* CreateJobStatus();
    ~XAFilmingJobStatusFactory() {SAFE_DELETE_ELEMENT(_instance)}
private:
    XAFilmingJobStatusFactory(){}
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobStatusFactory);
    static XAFilmingJobStatusFactory * _instance;
};

