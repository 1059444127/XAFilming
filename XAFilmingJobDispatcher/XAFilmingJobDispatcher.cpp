#include "XAFilmingJobDispatcher.h"
#include <XAFilmingLogger.h>
#include <XAFilmingSerializer.h>
#include <algorithm>

#ifndef XA_FILMING_JOB_MAP_DELEGATE
#define XA_FILMING_JOB_MAP_DELEGATE(Delegate)\
    {\
    for (auto iter = IDs.begin(); iter != IDs.end(); iter++)\
    {\
        int id = *iter;\
        if(_jobMap.find(id) == _jobMap.end())\
        {\
            LOG_WARN_XA_FILMING << "no job with ID [" << id << "]" << LOG_END;\
        }\
        else\
        {\
            auto job = _jobMap[id];\
            job->Delegate();\
        }\
    }\
}
#endif


XAFilmingJobDispatcher::XAFilmingJobDispatcher() : _jobMap()
{
}


XAFilmingJobDispatcher::~XAFilmingJobDispatcher()
{
    for(auto iter = _jobMap.begin(); iter != _jobMap.end(); iter++)
    {
        auto job = iter->second;
        SAFE_DELETE_ELEMENT(job);
    }
}

void XAFilmingJobDispatcher::AddJob(XAFilmingJobBase* job)
{
    LOG_INFO_XA_FILMING << "Add a filming job" << LOG_END;
    _jobMap[job->GetJobID()] = job;
    PushJobsProgress();
}

void XAFilmingJobDispatcher::ContinueJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Continue jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Continue);
    PushJobsProgress();
}

void XAFilmingJobDispatcher::DeleteJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Delete jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    for (auto iter = IDs.begin(); iter != IDs.end(); iter++)
    {
        int id = *iter;
        if(_jobMap.find(id) == _jobMap.end())
        {
            LOG_WARN_XA_FILMING << "no job with ID [" << id << "]" << LOG_END;
            continue;
        }
        auto job = _jobMap[id];
        if(!job->CanCancel())
        {
            LOG_WARN_XA_FILMING << "can't remove job [" << id << "], status; [" << job->GetJobStatus()->ToString() << LOG_END;
            continue;
        }
        
        _jobMap.erase(id);
                    LOG_WARN_XA_FILMING << "Removed job [" << id << "], status; [" << job->GetJobStatus()->ToString() << LOG_END;
    }

    PushJobsProgress();
}

void XAFilmingJobDispatcher::PauseJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Pause jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Pause);
    PushJobsProgress();
}

void XAFilmingJobDispatcher::RestartJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Restart jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Restart);
    PushJobsProgress();
}

void XAFilmingJobDispatcher::UrgentJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Urgent jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Urgent);
    PushJobsProgress();
}

void XAFilmingJobDispatcher::PushJobsProgress()
{
    vector<XAFilmingJobBase*> jobs;
    for(auto iter = _jobMap.begin(); iter != _jobMap.end(); iter++)
    {
        jobs.push_back(iter->second);
    }

    XAFilmingJobComparer comparer;
    sort(jobs.begin(), jobs.end(), comparer);

    //TODO: Converter to Serialized Info to JobManager
}
