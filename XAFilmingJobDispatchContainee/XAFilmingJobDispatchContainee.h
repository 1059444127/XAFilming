#pragma once

#include "XAFilmingMacro.h"
#include "McsfContainee\mcsf_containee_base.h"

#include "IXAFilmingJobDispatch.h"


class ICommunicationProxy;
class IEventHandler;
class ICommandHandler;
class IBigDataHandler;


class XAFilmingJobDispatchContainee : public MCSF_NAMESPACE_FOR_XA::IContainee
{
public:


	XAFilmingJobDispatchContainee(): m_pCommunicationProxy(nullptr), _filmingJobDispatcher(nullptr)
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
	virtual ~XAFilmingJobDispatchContainee();

private:
	IXAFilmingJobDispatch* _filmingJobDispatcher;
	MCSF_NAMESPACE_FOR_XA::ICommandHandler* _commandHandler;
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobDispatchContainee)
	MCSF_NAMESPACE_FOR_XA::ICommunicationProxy * m_pCommunicationProxy;
};

DECLARE_CONTAINEE(XAFilmingJobDispatchContainee);
