#pragma once

#include "IXAFilmingJobDispatch.h"

#include <map>
#include <IXAFilmingCommunicationProxy.h>

class FilmingJobDispatcher :
    public IXAFilmingJobDispatch
{
public:
    FilmingJobDispatcher(IXAFilmingCommunicationProxy* communicator);
    ~FilmingJobDispatcher();

    virtual void AddJob(XAFilmingJobBase* job);
    virtual void ContinueJobs(const std::vector<int>& IDs);
    virtual void DeleteJobs(const std::vector<int>& IDs);
    virtual void PauseJobs(const std::vector<int>& IDs);
    virtual void RestartJobs(const std::vector<int>& IDs);
    virtual void UrgentJobs(const std::vector<int>& IDs);
    virtual void PushJobsProgress();
	virtual void NofifyPrintStatus(bool bStatus);
	virtual int GetEstimatedTimeToFinish();
private:
    std::map<int, XAFilmingJobBase*> _jobMap;
    IXAFilmingCommunicationProxy* _communicator;

    std::vector<XAFilmingJobBase*> GetSortedJobVector();
};

