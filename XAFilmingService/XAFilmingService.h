// XAFilmingService.h

#pragma once

#include "stdafx.h"

#include "McsfContainee/mcsf_containee_interface.h"
#include "McsfNetBase/mcsf_netbase_interface.h"

MCSF_FILMING_BEGIN_NAMESPACE

class ICommunicationProxy;
class IEventHandler;
class ICommandHandler;
class IBigDataHandler;

class XAFilmingService  : public Mcsf::IContainee
{
public:
	XAFilmingService(void) : m_printDicomFileCommandHandler(NULL), m_printDataHeaderCommandHandler(NULL), m_pCommProxy(NULL) {}
	~XAFilmingService(void)
	{
		if(NULL != m_printDicomFileCommandHandler)
		{
			delete m_printDicomFileCommandHandler;
			m_printDicomFileCommandHandler = NULL;
		}
		if(NULL != m_printDataHeaderCommandHandler)
		{
			delete m_printDataHeaderCommandHandler;
			m_printDataHeaderCommandHandler = NULL;
		}
	}

	void Startup();
	void DoWork();
	bool Shutdown(bool bReboot);
	void SetCommunicationProxy(ICommunicationProxy* pProxy);
	void SetCustomConfigFile(const std::string& sFilename);
	std::list<std::string> GetRunningTasks();
	void StartShutdown(bool bReboot);
	int GetTaskRemainingProgress(std::list<TaskProgress> & taskProgress);

	// TODO: Comment on class / member
	// TODO: DisAllow copy and assign macro
	// TODO: Namespace
private:
	ICommunicationProxy* m_pCommProxy;
	ICommandHandler* m_printDicomFileCommandHandler;
	ICommandHandler* m_printDataHeaderCommandHandler;
};

DECLARE_CONTAINEE(XAFilmingService);
MCSF_FILMING_END_NAMESPACE

