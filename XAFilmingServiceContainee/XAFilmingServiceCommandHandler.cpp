#include "XAFilmingLogger.h"

#include "XAFilmingSerializer.h"
#include "XAPrint.h"

#include "XAFilmingServiceCommandHandler.h"

using namespace std;

int XAFilmingServiceCommandHandler::HandleCommand(const MCSF_NAMESPACE_FOR_XA::CommandContext* pContext, std::string* pReplyObject)
{
	assert(nullptr != pContext);
	assert(nullptr != pReplyObject);

	string serializedPaths = pContext->sSerializeObject;

	LOG_INFO_XA_FILMING << "Received Command [" << pContext->iCommandId << "] from [" << pContext->sSender 
				<< "] with message [" << serializedPaths << "]" << LOG_END;

	vector<string> stringVector;
	deserializeStrings(serializedPaths, stringVector);
	
	string printResult = MCSF_NAMESPACE_FOR_XA::print(stringVector);
	LOG_INFO_XA_FILMING << "Print Result is [" << printResult << "]" << LOG_END;

	*pReplyObject = printResult;

	return 0;
}
