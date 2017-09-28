#include "XAFilmingSampleCommandHandler.h"
#include <XAFilmingLogger.h>

int XAFilmingSampleCommandHandler::HandleCommand(const CommandContext* pContext, std::string* pReplyObject)
{
	*pReplyObject = XA_FILMING_EMPTY_STRING;
	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender << LOG_END;

	return 0;
}