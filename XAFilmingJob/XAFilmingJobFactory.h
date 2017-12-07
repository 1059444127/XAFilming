#pragma once
#include "XAFilmingJobExportMacro.h"
#include "XAFilmingJobBase.h"
#include "XAFilmingMacro.h"
#include <vector>
#include <map>

class XA_FilmingJob_Export XAFilmingJobFactory
{
public:
    static XAFilmingJobFactory* Instance();
    XAFilmingJobBase* CreateJob();
    XAFilmingJobBase* CreateFilmingJob(const std::vector<std::string>& dicomFiles);
	XAFilmingJobBase* CreateFilmingJob(const std::string& serializedDataheader);
	XAFilmingJobBase* BuildFilmingJob(const std::string& serializedDataheader);
    ~XAFilmingJobFactory() {SAFE_DELETE_ELEMENT(_instance);}

private:
    static XAFilmingJobFactory* _instance;
    static int _maxJobID;

	std::map<std::string, std::vector<IFilmingJobMetaData>> _pipeLineJobs;

    XAFilmingJobFactory() {};

	bool SplitSerializedDataheaderPacket(const std::string& serializedParameter, std::string& packetHeader, std::string& serializedDataheader);

    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobFactory)
};

