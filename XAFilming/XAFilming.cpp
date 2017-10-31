#include "XAFilming.h"
#include "XAFilmingLogger.h"
#include <XAPrint.h>

void XAFilming::Print(const std::vector<std::string>& filePaths)
{
	bool bResult = MCSF_NAMESPACE_FOR_XA::print(filePaths);
	LOG_INFO_XA_FILMING << "Print Success ? " << bResult << LOG_END;

	PublishPrintResult(bResult);
}

void XAFilming::Register(IPrintResultObserver* pObserver)
{
	LOG_INFO_XA_FILMING << "Register a printResultObserver " << LOG_END;
	_observers.push_back(pObserver);
}

void XAFilming::PublishPrintResult(bool bResult)
{
	for(auto iter = _observers.begin(); iter != _observers.end(); ++iter)
	{
		(*iter)->NofifyPrintStatus(bResult);
	}
}
