#pragma once
#include "XAFilmingMacro.h"
#include "XAFilmingJobDispatcherExportMacro.h"

class XA_FilmingJobDispatcher_Export XAFilmingJobDispatcherFactory
{
public:
    static XAFilmingJobDispatcherFactory* Instance();
    ~XAFilmingJobDispatcherFactory() {SAFE_DELETE_ELEMENT(_instance);}
private:
    static XAFilmingJobDispatcherFactory* _instance;
    XAFilmingJobDispatcherFactory() {};
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobDispatcherFactory);
};

