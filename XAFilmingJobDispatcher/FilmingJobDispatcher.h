#pragma once

#include "IXAFilmingJobDispatch.h"

#include "XAFilmingJobComparer.h"
#include <map>
#include <IXAFilmingCommunicator.h>

class FilmingJobDispatcher :
    public IXAFilmingJobDispatch
{
public:
    FilmingJobDispatcher(IXAFilmingCommunicator* communicator);
    ~FilmingJobDispatcher();

    virtual void AddJob(XAFilmingJobBase* job);
    virtual void ContinueJobs(const vector<int>& IDs);
    virtual void DeleteJobs(const vector<int>& IDs);
    virtual void PauseJobs(const vector<int>& IDs);
    virtual void RestartJobs(const vector<int>& IDs);
    virtual void UrgentJobs(const vector<int>& IDs);
    virtual void PushJobsProgress();
private:
    map<int, XAFilmingJobBase*> _jobMap;
    IXAFilmingCommunicator* _communicator;
};

