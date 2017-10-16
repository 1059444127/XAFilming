#include "XACommand.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"
#include "../../../XParameters/Contract/CommunicationCommandID.h"
#include <McsfNetBase/mcsf_netbase_command_context.h>

using namespace MCSF_NAMESPACE_FOR_XA;




void SendPrintCommand(const std::vector<std::string>& files, MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy, ICommandCallbackHandler* callback)
{
    std::string serializedString = serialize(files);
    LOG_INFO_XA_FILMING << "Print " << serializedString << LOG_END;

	CommandContext command_context;
	command_context.sSerializeObject = serializedString;
	command_context.iCommandId = COMMUNICATION_COMMAND_ID::COMMAND_ID_PRINT;
	command_context.sReceiver = "Filming@@";
	command_context.pCommandCallback = callback;

	pProxy->AsyncSendCommand(&command_context);
}
