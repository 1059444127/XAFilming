#include "XAFilmingServiceCommandHandler.h"
#include <XAFilmingLogger.h>

int XAFilmingServiceCommandHandler::HandleCommand(const CommandContext* pContext, std::string* pReplyObject)
{
	assert(nullptr != pContext);
	assert(nullptr != pReplyObject);

	*pReplyObject = "true";
	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender << LOG_END;

	//	vector<string> stringVector;
	//split(serializedPaths, PARAMETER_LIST_SEPARATOR, stringVector);
	//
	//Print(stringVector);

	return 0;
}
