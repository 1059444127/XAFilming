#pragma once
#include "IXAFilmingTestConfig.h"
#include <McsfFileParser/mcsf_file_parser_factory.h>

class TestConfig : public IXAFilmingTestConfig
{
public:
	TestConfig(std::string configPath);

	virtual bool GetToDelayJob();
	virtual int GetDelaySeconds();
	bool ReadConfigBeforeUsing();
	void ReadConfig();

private:
	bool _toDelayJob;
	int _delaySeconds;
	bool _readConfigBeforeUsing;
	Mcsf::IFileParser* _pFileParser;
};
