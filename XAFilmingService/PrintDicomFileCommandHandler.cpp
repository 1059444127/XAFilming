#include "StdAfx.h"
#include "PrintDicomFileCommandHandler.h"
#include "Utility.h"
#include "FilmingUtility.h"
#include <XAFilmingLogger.h>
#include <XAFilmingMacro.h>

using namespace StrUtil;

MCSF_FILMING_BEGIN_NAMESPACE


int MCSF_FILMING_NAMESPACE::PrintDicomFileCommandHandler::HandleCommand(const CommandContext* pContext,std::string* pReplyObject)
{
	*pReplyObject = XA_FILMING_EMPTY_STRING;
	assert(nullptr != pContext);
	assert(nullptr != pReplyObject);

	string serializedPaths = pContext->sSerializeObject;

	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender 
				<< "] with message [" << serializedPaths << "]" << LOG_END;


	vector<string> stringVector;
	split(serializedPaths, PARAMETER_LIST_SEPARATOR, stringVector);
	
	Print(stringVector);

	return 0;
}


MCSF_FILMING_END_NAMESPACE


