#pragma once

#include "McsfNetBase/mcsf_netbase_interface.h"

#include "XAFilmingMacro.h"


class XAFilmingSampleCommandHandler : public MCSF_NAMESPACE_FOR_XA::ICommandHandler
{
public:

	virtual int HandleCommand(const MCSF_NAMESPACE_FOR_XA::CommandContext* pContext, std::string* pReplyObject);

private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingSampleCommandHandler)
};