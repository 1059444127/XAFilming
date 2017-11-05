#include "PrinterConfig.h"


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

PrinterConfig::PrinterConfig(): _bReadConfigBeforeUsing(true)
{
}

void PrinterConfig::ReadConfig()
{
}

bool PrinterConfig::ReadConfigBeforeUsing()
{
	return _bReadConfigBeforeUsing;
}
