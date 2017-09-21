#pragma once

#include "McsfNetBase/mcsf_netbase_interface.h"

MCSF_FILMING_BEGIN_NAMESPACE

class PrintDataHeaderCommandHandler : public ICommandHandler
{
public:
	PrintDataHeaderCommandHandler(){}
	~PrintDataHeaderCommandHandler(){}

	/////////////////////////////////////////////////////////////////
	///  \brief     HandleCommand
	///
	///  \param[in]    const CommandContext* pContext
	///  \param[out]   std::string* pReplyObject
	///  \return       int
	///  \pre \e  
	/////////////////////////////////////////////////////////////////
	virtual int HandleCommand(const CommandContext* pContext,std::string* pReplyObject);
};

MCSF_FILMING_END_NAMESPACE