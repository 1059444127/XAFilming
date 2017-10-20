#include "CommunicationCommandID.h"

#include "XAFilmingServiceContainee.h"
#include "XAFilmingLogger.h"
#include <McsfContainee/mcsf_containee_cmd_id.h>

using namespace std;


IMPLEMENT_CONTAINEE(XAFilmingServiceContainee);

void XAFilmingServiceContainee::Startup()
{
	LOG_INFO_XA_FILMING << "Startup" << LOG_END;

	m_pCommunicationProxy->RegisterCommandHandler(COMMAND_ID_PRINT, m_pCommandHandler);
}

void XAFilmingServiceContainee::DoWork()
{
	LOG_INFO_XA_FILMING << "DoWork" << LOG_END;

	auto send_system_event_result = m_pCommunicationProxy->SendSystemEvent( "", static_cast<int>(MCSF_NAMESPACE_FOR_XA::SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY), m_pCommunicationProxy->GetName() );
	send_system_event_result ?
		LOG_ERROR_XA_FILMING << "Fail to send componet_ready event to System manager,Please restart the containee" << LOG_END
		:	LOG_ERROR_XA_FILMING << "Succeed to send componet_ready event to System manager" << LOG_END;
}

bool XAFilmingServiceContainee::Shutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "Shutdown with message bReboot ? [" << bReboot  << "]\n";
	return true;
}

void XAFilmingServiceContainee::SetCommunicationProxy(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
	LOG_INFO_XA_FILMING << "SetCommunicationProxy" << LOG_END;
	m_pCommunicationProxy = pProxy;
}

int XAFilmingServiceContainee::GetEstimatedTimeToFinishJob(bool bReboot)
{
	LOG_INFO_XA_FILMING << "GetEstimatedTmeToFinishJob with message bReboot ? [" << bReboot  << "]\n";
	return 0;
}

void XAFilmingServiceContainee::SetCustomConfigFile(const std::string& sFilename)
{
	//LOG_INFO_XA_FILMING << "CustomConfigFile: "  <<  sFilename << LOG_END;
}

std::list<std::string> XAFilmingServiceContainee::GetRunningTasks()
{
	return std::list<std::string>();
}

void XAFilmingServiceContainee::StartShutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "bReboot: "  <<  bReboot << LOG_END;
}

int XAFilmingServiceContainee::GetTaskRemainingProgress(std::list<MCSF_NAMESPACE_FOR_XA::TaskProgress> & taskProgress)
{
	LOG_INFO_XA_FILMING << "taskProgress.Count = "  <<  taskProgress.size() << LOG_END;
	return 0;
}

XAFilmingServiceContainee::~XAFilmingServiceContainee()
{
	LOG_INFO_XA_FILMING << "Destructor" << LOG_END;
	SAFE_DELETE_ELEMENT(m_pCommandHandler);
}

