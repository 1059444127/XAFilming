#pragma once
#include <vector>
#include "INotifyPrintStatus.h"

class XAFilmingJobBase;
class IXAFilmingJobDispatch : public INofifyPrintStatus
{
public:
    virtual void AddJob(XAFilmingJobBase *job) = 0;

    virtual void ContinueJobs(const std::vector<int>& IDs) = 0;
    virtual void DeleteJobs(const std::vector<int>& IDs) = 0;
    virtual void PauseJobs(const std::vector<int>& IDs) = 0;
    virtual void RestartJobs(const std::vector<int>& IDs) = 0;
    virtual void UrgentJobs(const std::vector<int>& IDs) = 0;

    virtual void PushJobsProgress()= 0;
    
};