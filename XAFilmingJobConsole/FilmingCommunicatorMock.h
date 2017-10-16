#pragma once
#include <IXAFilmingCommunicationProxy.h>

class FilmingCommunicatorMock :
    public IXAFilmingCommunicationProxy
{
public:
	virtual void Register(IPrintStatusObserver* pNotifier){}
	virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs);
    virtual void Print(const std::vector<std::string>& files);
};

