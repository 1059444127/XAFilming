#include "XAFilmingLogger.h"

#include "XAFilmingSerializer.h"
#include "XAPrint.h"

#include "XAFilmingServiceCommandHandler.h"
#include <sstream>

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
	
	bool printResult = MCSF_NAMESPACE_FOR_XA::print(stringVector);
	LOG_INFO_XA_FILMING << "Print Result is [" << printResult << "]" << LOG_END;

	stringstream ss;
	ss << printResult;

	*pReplyObject = ss.str();

	return 0;
}
