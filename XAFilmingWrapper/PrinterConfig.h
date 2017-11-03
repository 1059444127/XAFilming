#pragma once
#include "IXADicomPrinterProperty.h"
#include "XAFilmingMacro.h"

class PrinterConfig : public IXADicomPrinterProperty
{
public:
	static IXADicomPrinterProperty& Instance();
	virtual std::string GetAE();
	virtual std::string GetIP();
	virtual unsigned short GetPort();
	virtual std::string GetFilmSize();
private:
	bool _bReadConfigBeforeUsing;
	static PrinterConfig _instance;
	PrinterConfig();
	void ReadConfig();
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(PrinterConfig)
};
