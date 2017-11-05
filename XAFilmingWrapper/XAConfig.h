#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"
#include <IXADicomPrinterProperty.h>
#include <boost/thread/thread.hpp>
#include "PrinterConfig.h"


class XA_FilmingWrapper_Export XAConfig
{
public:
	static XAConfig* Instance();
	std::string GetPrinterConfigPath() const {return _printerConfigPath;}
	IXADicomPrinterProperty* GetPrinterConfig();
	virtual ~XAConfig();
private:
	static XAConfig* _pInstance;

	std::string _printerConfigPath;
	PrinterConfig* _pPrinterConfig;

	boost::mutex _printerConfigMutex;

	XAConfig();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAConfig)
};
