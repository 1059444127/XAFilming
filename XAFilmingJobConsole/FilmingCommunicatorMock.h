#pragma once
#include <IXAFilmingCommunicator.h>

class FilmingCommunicatorMock :
    public IXAFilmingCommunicator
{
public:
	virtual void Register(INofifyPrintStatus* pNotifier){}
	virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs);
    virtual void Print(const std::vector<std::string>& files);
};
