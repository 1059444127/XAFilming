#pragma once
#include <XAFilmingMacro.h>
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>
#include "IXAFilmingCommunicationProxy.h"

class FilmingCommunicator :
    public IXAFilmingCommunicationProxy
{
public:
	FilmingCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy);

    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs);
    virtual void Print(const std::vector<std::string>& files);

	virtual void Register(INofifyPrintStatus* pNotifier);
private:
	INofifyPrintStatus* _pNotifier;
	MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* _pProxy;
};

