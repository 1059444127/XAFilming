#include "PrintCallbackHandler.h"
#include <XAFilmingLogger.h>


int PrintCallbackHandler::HandleReply(const MCSF_NAMESPACE_FOR_XA::IAsyncResult* pAsyncResult)
{
	string result = pAsyncResult->GetMarshalObject();
	LOG_INFO_XA_FILMING << "Print Command Result : [" << result << "],  Call Result: [" << pAsyncResult->GetCallResult() << "]" << LOG_END;



	for (auto iter = _printStatusObservers.begin(); iter != _printStatusObservers.end(); iter++)
	{
		IPrintStatusObserver* pObserver = *iter;
		pObserver->NofifyPrintStatus(true);		///TODO: convert from callback result;
	}

	return 0;
}

void PrintCallbackHandler::Register(IPrintStatusObserver* pObserver)
{
	LOG_INFO_XA_FILMING << "Register a print status observer" << LOG_END;
	_printStatusObservers.push_back(pObserver);
}

PrintCallbackHandler::~PrintCallbackHandler()
{
	_printStatusObservers.clear();
}
