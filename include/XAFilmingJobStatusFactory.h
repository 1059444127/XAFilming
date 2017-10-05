#pragma once

#include "XAFilmingJobStatusExportMacro.h"
#include "XAFilmingMacro.h"
#include "XAFilmingJobStatusBase.h"

class XA_FilmingJobStatus_Export  XAFilmingJobStatusFactory
{
public:
    static XAFilmingJobStatusFactory* Instance();
    const XAFilmingJobStatusBase* CreateJobStatus();
private:
    XAFilmingJobStatusFactory(){}
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobStatusFactory);
    static XAFilmingJobStatusFactory * _instance;
};

