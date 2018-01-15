#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include "XAFilmingMacro.h"
#include <IXADicomPrinterProperty.h>
#include <boost/thread/thread.hpp>
#include "PrinterConfig.h"
#include "IXAFilmingTestConfig.h"
#include "TestConfig.h"


class XA_FilmingWrapper_Export XAConfig
{
public:
	static XAConfig* Instance();
	std::string GetPrinterConfigPath() const {return _printerConfigPath;}
	IXADicomPrinterProperty* GetPrinterConfig();
	virtual ~XAConfig();
	IXAFilmingTestConfig* GetTestConfig();
private:
	static XAConfig* _pInstance;

	std::string _printerConfigPath;
	std::string _testConfigPath;
	PrinterConfig* _pPrinterConfig;
	TestConfig *_pTestConfig;

	boost::mutex _printerConfigMutex;
	boost::mutex _testConfigMutex;

	XAConfig();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAConfig)
};
