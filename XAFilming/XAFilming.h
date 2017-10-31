#pragma once
#include "XAFilmingExportMacro.h"
#include "IXAFilming.h"
#include "IPrintResultSubject.h"

class XA_Filming_Export XAFilming : IXAFilming, IPrintResultSubject
{
public:
	virtual void Print(const std::vector<std::string>& filePaths);
	virtual void Register(IPrintResultObserver* pObserver);
private:
	std::vector<IPrintResultObserver*> _observers;
	void PublishPrintResult(bool bResult);
};
