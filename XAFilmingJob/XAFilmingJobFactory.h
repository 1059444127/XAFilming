#pragma once
#include "XAFilmingJobExportMacro.h"

class XA_FilmingJob_Export XAFilmingJobFactory
{
public:
    static XAFilmingJobFactory* Instance();
private:
    static XAFilmingJobFactory* _instance;
    XAFilmingJobFactory() {};
};

