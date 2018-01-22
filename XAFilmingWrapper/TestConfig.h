#pragma once
#include "IXAFilmingTestConfig.h"
#include "XAFilmingWrapperExportMacro.h"
#include "AbstractConfig.h"

class XA_FilmingWrapper_Export TestConfig : public AbstractConfig,  public IXAFilmingTestConfig
{
public:
	TestConfig(std::string configPath) : AbstractConfig(configPath), _toDelayJob(false), _delaySeconds(0) {}

	virtual bool GetToDelayJob() {return _toDelayJob;}
	virtual int GetDelaySeconds() {return _delaySeconds;}


	virtual void ReadConfigFromFile();
private:
	bool _toDelayJob;
	int _delaySeconds;

};
