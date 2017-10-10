#pragma once
#include <vector>
#include <XAFilmingJobBase.h>
#include "INotifyPrintStatus.h"
#include "IXAFilmingProxy.h"

class IXAFilmingCommunicationProxy : public IXAFilmingProxy
{
public:
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
	virtual void Register(INofifyPrintStatus* pNotifier) = 0;
};
