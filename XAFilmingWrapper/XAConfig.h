#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"
#include <string>

class XA_FilmingWrapper_Export XAConfig
{
public:
	static XAConfig* Instance();
	std::string GetPrinterConfigPath() const {return _printerConfigPath;}
private:
	static XAConfig _instance;

	std::string _printerConfigPath;

	XAConfig();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAConfig)
};
