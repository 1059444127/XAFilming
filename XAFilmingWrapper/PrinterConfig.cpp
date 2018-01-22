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

PrinterConfig::PrinterConfig(const std::string& configFilePath): AbstractConfig(configFilePath), _bReadConfigBeforeUsing(true), _port(XA_DEFAULT_DICOM_PRINTER_PORT)
{

}


void PrinterConfig::ReadConfig()
{
	LOG_INFO_XA_FILMING << "Read Printer Config" << LOG_END;
	if(ReadConfigBeforeUsing())
	{
		boost::mutex::scoped_lock lock(_configReadMutex);
		if(ReadConfigBeforeUsing())
		{
			ReadConfigFromFile();
		}
	}
}

bool PrinterConfig::ReadConfigBeforeUsing()
{
	return _bReadConfigBeforeUsing;
}

string PrinterConfig::GetStringByTag(const string& tag)
{
	LOG_INFO_XA_FILMING << "Get String by Tag : [" << tag << "]" << LOG_END;
	string result;
	if(!_pFileParser->GetStringValueByTag(tag, &result))  // use wstring before
	{
		LOG_WARN_XA_FILMING << "Fail to Get " << LOG_END;
	}
	LOG_INFO_XA_FILMING << "Value : [" << result << "]" << LOG_END;
	return result;
}

void PrinterConfig::ReadConfigFromFile()
{	
	try
	{
		LOG_INFO_XA_FILMING << "Read Printer Config using FileParser from file : " << _configFilePath << LOG_END;

		if(!_pFileParser->ParseByURI(_configFilePath))
		{
			LOG_ERROR_XA_FILMING << "Failed to Parse Printer Config" << LOG_END;
			return;
		}
		
		_ae = GetStringByTag("AE");
		_ip = GetStringByTag("IP");
		_filmSize = GetStringByTag("FilmSize");
		auto portString = GetStringByTag("Port");
		_port = boost::lexical_cast<unsigned short>(portString);
		auto readConfigBeforeUsingString = GetStringByTag("ReadConfigBeforeUsing");
		_bReadConfigBeforeUsing = boost::lexical_cast<bool>(readConfigBeforeUsingString);

	}
	catch (std::exception& e)
	{
		LOG_ERROR_XA_FILMING << "Exception: " << e.what() << LOG_END;
	}

}
