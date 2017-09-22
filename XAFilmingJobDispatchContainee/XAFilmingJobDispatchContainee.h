#pragma once

#include "XAFilmingMacro.h"
#include "McsfContainee\mcsf_containee_base.h"
using namespace MCSF_NAMESPACE_FOR_XA;

class ICommunicationProxy;
class IEventHandler;
class ICommandHandler;
class IBigDataHandler;

class XAFilmingJobDispatchContainee : public ContaineeBase
{
public:


	/**
	 * \brief Containee Startup
	 */
	void Startup() override;
	/**
	 * \brief Containee DoWork
	 */
	void DoWork() override;
	/**
	 * \brief Containee Shutdown
	 * \param bReboot if reboot or not
	 * \return ?
	 */
	bool Shutdown(bool bReboot) override;
	///**
	// * \brief 
	// * \param pProxy CommunicationProxy Created by Container
	// */
	//void SetCommunicationProxy(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy) override;
	/**
	 * \brief Estimate time to finish job for waiting system manager
	 * \param bReboot if reboot or not
	 * \return time left to finish job , unit: ms
	 */
	virtual int GetEstimatedTimeToFinishJob(bool bReboot);

	virtual ~XAFilmingJobDispatchContainee();

private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingJobDispatchContainee)
};

DECLARE_CONTAINEE(XAFilmingJobDispatchContainee);

