#pragma once
#include "XAFilmingJobExportMacro.h"
#include "XAFilmingJobBase.h"
#include "XAFilmingMacro.h"
#include <vector>

class XA_FilmingJob_Export XAFilmingJobFactory
{
public:
    static XAFilmingJobFactory* Instance();
    XAFilmingJobBase* CreateJob();
    XAFilmingJobBase* CreateFilmingJob(std::vector<std::string> dicomFiles);
	XAFilmingJobBase* BuildFilmingJob(std::string serializedDataheader);
    ~XAFilmingJobFactory() {SAFE_DELETE_ELEMENT(_instance);}

private:
    static XAFilmingJobFactory* _instance;
    static int _maxJobID;
    XAFilmingJobFactory() {};
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobFactory)
};

