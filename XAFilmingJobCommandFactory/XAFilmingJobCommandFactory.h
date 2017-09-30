#pragma once

#include "XAFilmingMacro.h"

#include "XAFilmingJobCommandFactoryExportMacro.h"

class XA_XAFilmingJobCommandFactory_Export XAFilmingJobCommandFactory
{
public:
	static  XAFilmingJobCommandFactory* GetInstance();
	~XAFilmingJobCommandFactory() {};
private:
	static XAFilmingJobCommandFactory* _pInstance;

	XAFilmingJobCommandFactory() {}
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobCommandFactory)
};

