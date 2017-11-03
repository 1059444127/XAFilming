#include "PrinterConfig.h"

IXADicomPrinterProperty& PrinterConfig::Instance()
{	
}

std::string PrinterConfig::GetAE()
{
	throw ;
}

std::string PrinterConfig::GetIP()
{
	throw ;
}

unsigned short PrinterConfig::GetPort()
{
	throw ;
}

std::string PrinterConfig::GetFilmSize()
{
	throw ;
}

PrinterConfig::PrinterConfig()
{
}

void PrinterConfig::ReadConfig()
{
}
