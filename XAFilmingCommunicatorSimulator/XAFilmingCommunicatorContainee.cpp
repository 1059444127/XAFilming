#include "XAFilmingCommunicatorContainee.h"
#include "XAFilmingLogger.h"
#include <McsfContainee/mcsf_containee_cmd_id.h>


IMPLEMENT_CONTAINEE(XAFilmingCommunicatorContainee);

void XAFilmingCommunicatorContainee::Startup()
{
	LOG_INFO_XA_FILMING << "Startup" << LOG_END;

	if (nullptr == m_pCommunicationProxy)
	{
		LOG_WARN_XA_FILMING << "the pProxy is null for the containee" << LOG_END;
		return;
	}

}

void XAFilmingCommunicatorContainee::DoWork()
{
	LOG_INFO_XA_FILMING << "DoWork" << LOG_END;

	auto send_system_event_result = m_pCommunicationProxy->SendSystemEvent( "", static_cast<int>(SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY), m_pCommunicationProxy->GetName() );
	send_system_event_result ?
			LOG_ERROR_XA_FILMING << "Fail to send componet_ready event to System manager,Please restart the containee" << LOG_END
		:	LOG_ERROR_XA_FILMING << "Succeed to send componet_ready event to System manager" << LOG_END;
}

bool XAFilmingCommunicatorContainee::Shutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "Shutdown with message bReboot ? [" << bReboot  << "]\n";
	return true;
}

void XAFilmingCommunicatorContainee::SetCommunicationProxy(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
	LOG_INFO_XA_FILMING << "SetCommunicationProxy" << LOG_END;
	m_pCommunicationProxy = pProxy;
}

int XAFilmingCommunicatorContainee::GetEstimatedTimeToFinishJob(bool bReboot)
{
	LOG_INFO_XA_FILMING << "GetEstimatedTmeToFinishJob with message bReboot ? [" << bReboot  << "]\n";
	return 0;
}

void XAFilmingCommunicatorContainee::SetCustomConfigFile(const std::string& sFilename)
{
	LOG_INFO_XA_FILMING << "CustomConfigFile: "  <<  sFilename << LOG_END;
}

std::list<std::string> XAFilmingCommunicatorContainee::GetRunningTasks()
{
	return std::list<std::string>();
}

void XAFilmingCommunicatorContainee::StartShutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "bReboot: "  <<  bReboot << LOG_END;
}

int XAFilmingCommunicatorContainee::GetTaskRemainingProgress(std::list<TaskProgress> & taskProgress)
{
	LOG_INFO_XA_FILMING << "taskProgress.Count = "  <<  taskProgress.size() << LOG_END;
	return 0;
}

XAFilmingCommunicatorContainee::~XAFilmingCommunicatorContainee()
{
	LOG_INFO_XA_FILMING << "Destructor" << LOG_END;
}

