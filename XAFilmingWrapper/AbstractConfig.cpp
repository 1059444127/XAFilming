#include "AbstractConfig.h"
#include <XAConfig.h>
#include "XAFilmingLogger.h"
#include <boost/lexical_cast.hpp>

AbstractConfig::AbstractConfig(const std::string& configFilePath) : _configFilePath(configFilePath), _bReadConfigBeforeUsing(true)
{
	_pFileParser = Mcsf::ConfigParserFactory::Instance()->GetXmlFileParser();
	_pFileParser->Initialize();
}

AbstractConfig::~AbstractConfig()
{
	if(nullptr != _pFileParser)
	{
		_pFileParser->Terminate();
		delete _pFileParser;
		_pFileParser = nullptr;
	}
}

void AbstractConfig::ReadConfig()
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

bool AbstractConfig::ReadConfigBeforeUsing()
{
	return _bReadConfigBeforeUsing;
}

void AbstractConfig::ReadConfigFromFile()
{
	LOG_INFO_XA_FILMING << "Read Printer Config using FileParser from file : " << _configFilePath << LOG_END;

	if(!_pFileParser->ParseByURI(_configFilePath))
	{
		LOG_ERROR_XA_FILMING << "Failed to Parse Config" << LOG_END;
		throw new exception("Fail to Parse Config");
	}

	auto readConfigBeforeUsingString = GetStringByTag("ReadConfigBeforeUsing");
	_bReadConfigBeforeUsing = boost::lexical_cast<bool>(readConfigBeforeUsingString);
}

std::string AbstractConfig::GetStringByTag(const std::string& tag)
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
