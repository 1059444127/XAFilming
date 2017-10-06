#pragma once
#include <vector>

class XAFilmingJobBase;
using namespace std;
class IXAFilmingJobDispatch
{
    virtual void AddJob(XAFilmingJobBase *job);

    virtual void ContinueJobs(const vector<int>& IDs) = 0;
    virtual void DeleteJobs(const vector<int>& IDs) = 0;
    virtual void PauseJobs(const vector<int>& IDs) = 0;
    virtual void RestartJobs(const vector<int>& IDs) = 0;
    virtual void UrgentJobs(const vector<int>& IDs) = 0;
    
    virtual void PushJobsProgress()= 0;
    
};