#include "XAFilmingLogger.h"

#include "XAFilmingSerializer.h"
#include "XAPrint.h"

#include "XAFilmingServiceCommandHandler.h"

int XAFilmingServiceCommandHandler::HandleCommand(const CommandContext* pContext, std::string* pReplyObject)
{
	assert(nullptr != pContext);
	assert(nullptr != pReplyObject);

	string serializedPaths = pContext->sSerializeObject;

	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender 
				<< "] with message [" << serializedPaths << "]" << LOG_END;

	vector<string> stringVector;
	deserializeStrings(serializedPaths, stringVector);
	
	bool printResult = print(stringVector);
	LOG_INFO_XA_FILMING << "Print Result is [" << printResult << "]" << LOG_END;

	stringstream ss;
	ss << printResult;

	*pReplyObject = ss.str();

	return 0;
}
