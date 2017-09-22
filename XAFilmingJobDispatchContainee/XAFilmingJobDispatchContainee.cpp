#include "XAFilmingJobDispatchContainee.h"
#include "XAFilmingLogger.h"


void XAFilmingJobDispatchContainee::Startup()
{
	LOG_INFO_XA_FILMING << "Startup" << "\n";
}

void XAFilmingJobDispatchContainee::DoWork()
{
	LOG_INFO_XA_FILMING << "DoWork" << "\n";
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

