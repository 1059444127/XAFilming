#include "XAFilmingLogger.h"


#include "XAFilmingJobCommandHandler.h"
#include "XAFilmingJobCommandFactory.h"

int XAFilmingJobCommandHandler::HandleCommand(const CommandContext* pContext, std::string* pReplyObject)
{
	*pReplyObject = XA_FILMING_EMPTY_STRING;
	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender << LOG_END;

	auto jobCommandFactory = XAFilmingJobCommandFactory::GetInstance();
	auto jobCommand = jobCommandFactory->GetFilmingCommand(pContext->iCommandId, _jobDispatcher);
	jobCommand->Excute(pContext->sSerializeObject);

	return 0;
}
