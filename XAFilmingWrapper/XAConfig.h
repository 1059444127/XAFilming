#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"
#include <string>
#include <IXADicomPrinterProperty.h>

class XA_FilmingWrapper_Export XAConfig
{
public:
	static XAConfig* Instance();
	std::string GetPrinterConfigPath() const {return _printerConfigPath;}
	IXADicomPrinterProperty* GetPrinterConfig();
	virtual ~XAConfig();
private:
	static XAConfig _instance;

	std::string _printerConfigPath;
	IXADicomPrinterProperty* _pPrinterConfig;

	XAConfig();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAConfig)
};
