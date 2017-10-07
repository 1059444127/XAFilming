#pragma once

#include "XAFilmingMacro.h"

#include "XAFilmingJobCommandFactoryExportMacro.h"
#include "IXAFilmingJobDispatch.h"
#include "JobCommandBase.h"

#include <map>
using namespace std;

class XA_XAFilmingJobCommand_Export XAFilmingJobCommandFactory
{
public:
	static  XAFilmingJobCommandFactory* GetInstance();
    IXAFilmingCommand* GetFilmingCommand(int commandID, IXAFilmingJobDispatch* jobDispatcher);
    ~XAFilmingJobCommandFactory();;
private:
	static XAFilmingJobCommandFactory* _pInstance;

    map<int, JobCommandBase*> _filmingCommandDictionary;
    XAFilmingJobCommandFactory();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobCommandFactory)
};

