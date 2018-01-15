#pragma once

class IXAFilmingTestConfig
{
public:
	virtual bool GetToDelayJob() = 0;
	virtual int GetDelaySeconds() = 0;
};