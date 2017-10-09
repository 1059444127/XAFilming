#pragma once
#include <vector>
#include <XAFilmingJobBase.h>
#include "INotifyPrintStatus.h"

class IXAFilmingCommunicator
{
public:
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
    virtual void Print(const std::vector<std::string>& files) = 0;
	virtual void Register(INofifyPrintStatus* pNotifier) = 0;
};
