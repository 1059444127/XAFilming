#pragma once
#include <XAFilmingMacro.h>
#include "McsfNetBase/mcsf_netbase_interface.h"
#include <IPrintStatusSubject.h>

class IPrintCallbackHandler : public MCSF_NAMESPACE_FOR_XA::ICommandCallbackHandler, public IPrintStatusSubject
{
	
};
