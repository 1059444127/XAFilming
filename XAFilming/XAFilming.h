#pragma once
#include "XAFilmingExportMacro.h"
#include "IXAFilming.h"
#include "IPrintStatusSubject.h"

class XA_Filming_Export XAFilming : IXAFilming, IPrintStatusSubject
{
public:
	virtual void Print(const std::vector<std::string>& filePaths);
	virtual void Register(IPrintStatusObserver* pObserver);
};
