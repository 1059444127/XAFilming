#include "AbstractConfig.h"
#include <XAConfig.h>

AbstractConfig::AbstractConfig(const std::string& configFilePath) : _configFilePath(configFilePath)
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
