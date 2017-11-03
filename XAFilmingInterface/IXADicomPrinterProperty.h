#pragma once
#include <string>

class IXADicomPrinterProperty
{
	virtual std::string GetAE() = 0;
	virtual std::string GetIP() = 0;
	virtual unsigned short GetPort() = 0;
	virtual std::string GetFilmSize() = 0;
};