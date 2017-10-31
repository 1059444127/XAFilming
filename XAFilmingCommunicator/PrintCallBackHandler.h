#pragma once
#include <XAFilmingMacro.h>
#include "McsfNetBase/mcsf_netbase_interface.h"
#include "IPrintCallbackHandler.h"

class PrintCallbackHandler : public IPrintCallbackHandler
{
public:

	PrintCallbackHandler()
		: _printStatusObservers()	{	}

	virtual int HandleReply(const MCSF_NAMESPACE_FOR_XA::IAsyncResult* pAsyncResult);

	virtual void Register(IPrintResultObserver* pObserver);

	virtual ~PrintCallbackHandler();

private:
	std::list<IPrintResultObserver*> _printStatusObservers;
};

