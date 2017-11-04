#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"

class XA_FilmingWrapper_Export XAConfig
{
public:
	static XAConfig* Instance();
private:
	static XAConfig _instance;
	XAConfig(){}
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAConfig)
};