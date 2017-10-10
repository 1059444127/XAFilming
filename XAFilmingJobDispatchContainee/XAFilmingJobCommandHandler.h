#pragma once

#include "McsfNetBase/mcsf_netbase_interface.h"

#include "XAFilmingMacro.h"
#include "IXAFilmingJobDispatch.h"
using namespace MCSF_NAMESPACE_FOR_XA;


class XAFilmingJobCommandHandler : public MCSF_NAMESPACE_FOR_XA::ICommandHandler
{
public:

	XAFilmingJobCommandHandler(IXAFilmingJobDispatch* ixa_filming_job_dispatch)
		: _jobDispatcher(ixa_filming_job_dispatch)
	{
	}

	virtual int HandleCommand(const CommandContext* pContext, std::string* pReplyObject);

private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobCommandHandler)
	IXAFilmingJobDispatch* _jobDispatcher;
};