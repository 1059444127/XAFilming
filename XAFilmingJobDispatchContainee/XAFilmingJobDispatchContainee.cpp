#include "XAFilmingJobDispatchContainee.h"
#include "XAFilmingLogger.h"
#include <McsfContainee/mcsf_containee_cmd_id.h>


void XAFilmingJobDispatchContainee::Startup()
{
	LOG_INFO_XA_FILMING << "Startup" << "\n";

	if (nullptr == m_pCommunicationProxy)
	{
		LOG_WARN_XA_FILMING << "the pProxy is null for the containee" << "\n";
		return;
	}

}

void XAFilmingJobDispatchContainee::DoWork()
{
	LOG_INFO_XA_FILMING << "DoWork" << "\n";

	auto send_system_event_result = m_pCommunicationProxy->SendSystemEvent( "", static_cast<int>(SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY), m_pCommunicationProxy->GetName() );
	send_system_event_result ?
			LOG_ERROR_XA_FILMING << "Fail to send componet_ready event to System manager,Please restart the containee" << "\n"
		:	LOG_ERROR_XA_FILMING << "Succeed to send componet_ready event to System manager" << "\n";
}

bool XAFilmingJobDispatchContainee::Shutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "Shutdown with message bReboot ? [" << bReboot  << "]\n";
	return true;
}

//void XAFilmingJobDispatchContainee::SetCommunicationProxy(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
//{
//	LOG_INFO_XA_FILMING << "SetCommunicationProxy" << "\n";
//	m_pCommunicationProxy = pProxy;
//}

int XAFilmingJobDispatchContainee::GetEstimatedTimeToFinishJob(bool bReboot)
{
	LOG_INFO_XA_FILMING << "GetEstimatedTmeToFinishJob with message bReboot ? [" << bReboot  << "]\n";
	return 0;
}

XAFilmingJobDispatchContainee::~XAFilmingJobDispatchContainee()
{
	LOG_INFO_XA_FILMING << "Destructor" << "\n";
}

