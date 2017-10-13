#pragma once

#include "XAFilmingMacro.h"
#include "McsfContainee\mcsf_containee_base.h"
#include <IXAFilmingCommunicationProxy.h>

class ICommunicationProxy;
class IEventHandler;
class ICommandHandler;
class IBigDataHandler;


class XAFilmingCommunicatorContainee : public MCSF_NAMESPACE_FOR_XA::IContainee
{
public:


	XAFilmingCommunicatorContainee(): m_pCommunicationProxy(nullptr)
	{
	}

	/**
	 * \brief Containee Startup
	 */
	void Startup() ;
	/**
	 * \brief Containee DoWork
	 */
	void DoWork() ;
	/**
	 * \brief Containee Shutdown
	 * \param bReboot if reboot or not
	 * \return ?
	 */
	bool Shutdown(bool bReboot) ;
	///**
	// * \brief 
	// * \param pProxy CommunicationProxy Created by Container
	// */
	void SetCommunicationProxy(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy) ;
	/**
	 * \brief Estimate time to finish job for waiting system manager
	 * \param bReboot if reboot or not
	 * \return time left to finish job , unit: ms
	 */
	virtual int GetEstimatedTimeToFinishJob(bool bReboot);

	virtual void SetCustomConfigFile(const std::string& sFilename);
	virtual std::list<std::string> GetRunningTasks();
	virtual void StartShutdown(bool bReboot);
	virtual int GetTaskRemainingProgress(std::list<MCSF_NAMESPACE_FOR_XA::TaskProgress>& taskProgress);
	virtual ~XAFilmingCommunicatorContainee();

private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingCommunicatorContainee)
	MCSF_NAMESPACE_FOR_XA::ICommunicationProxy * m_pCommunicationProxy;

	void Simulate();
};

DECLARE_CONTAINEE(XAFilmingCommunicatorContainee);
