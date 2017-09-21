#pragma once

using namespace std;

#include "McsfNetBase/mcsf_netbase_interface.h"

MCSF_FILMING_BEGIN_NAMESPACE

class PrintDicomFileCommandHandler : public ICommandHandler
{
public:
	PrintDicomFileCommandHandler(void){}

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
