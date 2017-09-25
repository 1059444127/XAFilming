// This is the main DLL file.

#include "stdafx.h"

#include <iostream>

#include "McsfContainee\mcsf_containee_cmd_id.h"

#include "PrintDicomFileCommandHandler.h"
#include "PrintDataHeaderCommandHandler.h"

#include "XAFilmingService.h"
#include "XAFilmingLogger.h"
#include <XAFilmingMacro.h>


using namespace std;

MCSF_FILMING_BEGIN_NAMESPACE

IMPLEMENT_CONTAINEE(XAFilmingService);

void XAFilmingService::Startup()
{
	LOG_INFO_XA_FILMING << "Startup" << LOG_END;

	if (NULL == m_pCommProxy)
	{
		LOG_WARN_XA_FILMING << "the pProxy is null for the containee" << LOG_END;
		return;
	}

	m_printDicomFileCommandHandler = new PrintDicomFileCommandHandler();
	m_pCommProxy->RegisterCommandHandler(COMMAND_ID_FILMING, m_printDicomFileCommandHandler);

	m_printDataHeaderCommandHandler = new PrintDataHeaderCommandHandler();
	m_pCommProxy->RegisterCommandHandler(COMMAND_ID_FILMING_DATAHEADER, m_printDataHeaderCommandHandler);
	
}

void XAFilmingService::DoWork()
{
	LOG_INFO_XA_FILMING << "DoWork" << LOG_END;

	if(NULL == m_pCommProxy || m_pCommProxy->SendSystemEvent( "", static_cast<int>(SYSTEM_COMMAND_EVENT_ID_COMPONENT_READY), m_pCommProxy->GetName() ) )
	{
		LOG_ERROR_XA_FILMING << "The event send to System manager fail,Please restart the Filming Service" << LOG_END;
	}	
}

bool XAFilmingService::Shutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "bReboot: "  <<  bReboot << LOG_END;
	return false;
}

void XAFilmingService::SetCommunicationProxy(ICommunicationProxy* pProxy)
{
	if (NULL == pProxy)
	{
		LOG_WARN_XA_FILMING << "the pProxy is null for the containee" << LOG_END;
	}

	m_pCommProxy = pProxy;

	LOG_INFO_XA_FILMING << "End to SetCommunicationProxy" << LOG_END;
}

void XAFilmingService::SetCustomConfigFile(const std::string& sFilename)
{
	LOG_INFO_XA_FILMING << "CustomConfigFile: "  <<  sFilename << LOG_END;
}

std::list<std::string> XAFilmingService::GetRunningTasks()
{
	return std::list<std::string>();
}

void XAFilmingService::StartShutdown(bool bReboot)
{
	LOG_INFO_XA_FILMING << "bReboot: "  <<  bReboot << LOG_END;
}

int XAFilmingService::GetTaskRemainingProgress(std::list<TaskProgress> & taskProgress)
{
	LOG_INFO_XA_FILMING << "taskProgress.Count = "  <<  taskProgress.size() << LOG_END;
	return 0;
}

MCSF_FILMING_END_NAMESPACE


