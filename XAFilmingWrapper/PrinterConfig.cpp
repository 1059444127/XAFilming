#include "PrinterConfig.h"
#include <XAFilmingConst.h>
#include <McsfFileParser/mcsf_file_parser_factory.h>
#include "XAFilmingLogger.h"
#include "boost/lexical_cast.hpp"

using namespace MCSF_NAMESPACE_FOR_XA;


std::string PrinterConfig::GetAE()
{
	return _ae;
}

std::string PrinterConfig::GetIP()
{
	return _ip;
}

unsigned short PrinterConfig::GetPort()
{
	return _port;
}

std::string PrinterConfig::GetFilmSize()
{
	return _filmSize;
}

PrinterConfig::PrinterConfig(const std::string& configFilePath): AbstractConfig(configFilePath), _port(XA_DEFAULT_DICOM_PRINTER_PORT)
{

}


void PrinterConfig::ReadConfigFromFile()
{	
	try
	{
		AbstractConfig::ReadConfigFromFile();
		
		_ae = GetStringByTag("AE");
		_ip = GetStringByTag("IP");
		_filmSize = GetStringByTag("FilmSize");
		auto portString = GetStringByTag("Port");
		_port = boost::lexical_cast<unsigned short>(portString);

	}
	catch (std::exception& e)
	{
		LOG_ERROR_XA_FILMING << "Exception: " << e.what() << LOG_END;
	}

}
