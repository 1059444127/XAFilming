#pragma once
#include <vector>
#include <XAFilmingJobBase.h>
#include "INotifyPrintStatus.h"
#include "IXAFilming.h"

class IXAFilmingCommunicationProxy : public IXAFilming
{
public:
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
	virtual void Register(INofifyPrintStatus* pNotifier) = 0;
};
