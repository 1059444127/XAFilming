#include "XAFilming.h"
#include "XAFilmingLogger.h"
#include <XAPrint.h>
#include <cassert>
#include <XAPrintStatus.h>

#include <boost/thread/thread.hpp>


void XAFilming::Print(const std::vector<std::string>& filePaths)
{
	assert(!IsPrinting());

	SetPrinting(true);
	bool bResult = MCSF_NAMESPACE_FOR_XA::print(filePaths);	//TODO: Modify as a new thread
	SetPrinting(false);
	
	LOG_INFO_XA_FILMING << "Print Success ? " << bResult << LOG_END;

	PublishPrintResult(bResult);

	//boost::thread thrd(boost::bind())
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
		(*iter)->NotifyPrintResult(bResult);
	}
}
