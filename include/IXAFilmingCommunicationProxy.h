#pragma once
#include <vector>
#include <XAFilmingJobBase.h>
#include "IPrintResultObserver.h"
#include "IXAFilming.h"
#include "IPrintResultSubject.h"

class IXAFilmingCommunicationProxy : public IXAFilming, public IPrintResultSubject
{
public:
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
	virtual void Register(IPrintResultObserver* pObserver) = 0;
};
