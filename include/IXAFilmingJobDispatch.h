#pragma once
#include <vector>

class XAFilmingJobBase;
using namespace std;
class IXAFilmingJobDispatch
{
public:
    virtual void AddJob(XAFilmingJobBase *job) = 0;

    virtual void ContinueJobs(const vector<int>& IDs) = 0;
    virtual void DeleteJobs(const vector<int>& IDs) = 0;
    virtual void PauseJobs(const vector<int>& IDs) = 0;
    virtual void RestartJobs(const vector<int>& IDs) = 0;
    virtual void UrgentJobs(const vector<int>& IDs) = 0;

    virtual void PushJobsProgress()= 0;
    
    virtual void Printed() = 0;
};