#pragma once

class IXAFilmingTestConfig
{
public:
	virtual bool ToDelayJob() = 0;
	virtual int DelaySeconds() = 0;
};