#include "FilmingCommunicator.h"
#include "XAFilmingLogger.h"
#include "XAFilmingSerializer.h"
#include <McsfNetBase/mcsf_netbase_command_context.h>
#include <McsfJobManagerInfoWrapper.h>
#include "../../../XParameters/Contract/CommunicationCommandID.h"
#include <McsfNetBase/mcsf_communication_node_name.h>

using namespace MCSF_NAMESPACE_FOR_XA;

FilmingCommunicator::FilmingCommunicator(ICommunicationProxy* pProxy): _pProxy(pProxy), _pNotifier(nullptr)
{
}

void FilmingCommunicator::PublishJobProgress(const vector<XAFilmingJobBase*>& jobs)
{
    LOG_INFO_XA_FILMING << "publish job progress" << LOG_END;

	CommandContext command_context;
	command_context.sSerializeObject = SerializeFrom(jobs);
	command_context.iCommandId = COMMAND_ID_PRINT;
	command_context.sReceiver =  CommunicationNodeName::CreateCommunicationProxyName(""); //TODO: Dependency Injection of ComunicationName
	
	_pProxy->AsyncSendCommand(&command_context);
}

void FilmingCommunicator::Print(const vector<std::string>& files)
{
    string serializedString = serialize(files);
    LOG_INFO_XA_FILMING << "Print " << serializedString << LOG_END;
}

void FilmingCommunicator::Register(INofifyPrintStatus* pNotifier)
{
	_pNotifier = pNotifier;
}
