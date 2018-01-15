#pragma once
#include <string>
#include "IXAFilmingTestConfig.h"

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
};
