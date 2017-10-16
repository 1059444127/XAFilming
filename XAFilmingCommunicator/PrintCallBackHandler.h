#pragma once
#include <XAFilmingMacro.h>
#include "McsfNetBase/mcsf_netbase_interface.h"

class PrintCallBackHandler : public MCSF_NAMESPACE_FOR_XA::ICommandCallbackHandler
{
public:
	PrintCallBackHandler(void);
	~PrintCallBackHandler(void);
};

