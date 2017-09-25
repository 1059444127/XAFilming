#include "XAFilmingServiceCommandHandler.h"
#include <XAFilmingLogger.h>

int XAFilmingServiceCommandHandler::HandleCommand(const CommandContext* pContext, std::string* pReplyObject)
{
	*pReplyObject = EMPTY_STRING;
	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender << LOG_END;

	return 0;
}
