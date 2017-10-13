#pragma once

#include "XAFilmingMacro.h"

#include "XAFilmingJobCommandFactoryExportMacro.h"
#include "IXAFilmingJobDispatch.h"
#include "XAFilmingJobCommandBase.h"

#include <map>

class XA_XAFilmingJobCommand_Export XAFilmingJobCommandFactory
{
public:
	static  XAFilmingJobCommandFactory* GetInstance();
    IXAFilmingCommand* GetFilmingCommand(int commandID, IXAFilmingJobDispatch* jobDispatcher);
    ~XAFilmingJobCommandFactory();;
private:
	static XAFilmingJobCommandFactory* _pInstance;

    std::map<int, XAFilmingJobCommandBase*> _filmingCommandDictionary;
    XAFilmingJobCommandFactory();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobCommandFactory)
};

