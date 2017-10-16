#pragma once
#include <XAFilmingMacro.h>
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>
#include "IXAFilmingCommunicationProxy.h"

class FilmingCommunicator :
    public IXAFilmingCommunicationProxy
{
public:
	FilmingCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy, MCSF_NAMESPACE_FOR_XA::ICommandCallbackHandler* pCallbackHandler);

    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs);
    virtual void Print(const std::vector<std::string>& files);

	virtual void Register(IPrintStatusObserver* pNotifier);
private:
	IPrintStatusObserver* _pNotifier;
	MCSF_NAMESPACE_FOR_XA::ICommandCallbackHandler* _pCallbackHandler;
	MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* _pProxy;
};

