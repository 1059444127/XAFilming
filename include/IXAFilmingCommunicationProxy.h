#pragma once
#include <vector>
#include <XAFilmingJobBase.h>
#include "IPrintStatusObserver.h"
#include "IXAFilming.h"
#include "IPrintStatusSubject.h"

class IXAFilmingCommunicationProxy : public IXAFilming, public IPrintStatusSubject
{
public:
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
	virtual void Register(IPrintStatusObserver* pObserver) = 0;
};
