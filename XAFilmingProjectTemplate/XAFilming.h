#pragma once
#include "IXAFilming.h"
#include "IPrintStatusSubject.h"

class XAFilming : IXAFilming, IPrintStatusSubject
{
public:
	virtual void Print(const std::vector<std::string>& filePaths);
	virtual void Register(IPrintStatusObserver* pObserver);
};
