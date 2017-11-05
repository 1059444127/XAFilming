#pragma once
#include "IXADicomPrinterProperty.h"
#include "XAFilmingMacro.h"

class PrinterConfig : public IXADicomPrinterProperty
{
public:
	PrinterConfig();
	virtual std::string GetAE();
	virtual std::string GetIP();
	virtual unsigned short GetPort();
	virtual std::string GetFilmSize();
	void ReadConfig();
	bool ReadConfigBeforeUsing();
private:
	bool _bReadConfigBeforeUsing;
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(PrinterConfig)
};
