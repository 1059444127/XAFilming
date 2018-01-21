#include "TestConfig.h"
#include <McsfFileParser/mcsf_file_parser_factory.h>

TestConfig::TestConfig(std::string configPath) : _toDelayJob(false), _delaySeconds(0), _readConfigBeforeUsing(true)
{
	_pFileParser = Mcsf::ConfigParserFactory::Instance()->GetXmlFileParser();
	_pFileParser->Initialize();
}

bool TestConfig::GetToDelayJob()
{
	return _toDelayJob;
}

int TestConfig::GetDelaySeconds()
{
	return _delaySeconds;
}

bool TestConfig::ReadConfigBeforeUsing()
{
	return _readConfigBeforeUsing;
}

void TestConfig::ReadConfig()
{
}
