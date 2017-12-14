#pragma once
#include <XAFilmingMacro.h>
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>
#include "IXAFilmingCommunicationProxy.h"

class IPrintCallbackHandler;

class FilmingCommunicator :
    public IXAFilmingCommunicationProxy
{
public:
	FilmingCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy, IPrintCallbackHandler* pCallbackHandler);

    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs);
    virtual void Print(const std::vector<std::string>& files);

	virtual void Register(IPrintResultObserver* pObserver);
	virtual void UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData);
private:
	IPrintCallbackHandler* _pCallbackHandler;
	MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* _pProxy;
};

