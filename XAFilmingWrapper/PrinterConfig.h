#pragma once
#include "IXADicomPrinterProperty.h"

class PrinterConfig : public IXADicomPrinterProperty
{
public:
	virtual std::string GetAE();
	virtual std::string GetIP();
	virtual unsigned short GetPort();
	virtual std::string GetFilmSize();
};
