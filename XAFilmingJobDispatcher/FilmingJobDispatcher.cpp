#include "FilmingJobDispatcher.h"
#include <XAFilmingLogger.h>
#include <XAFilmingSerializer.h>
#include <algorithm>
#include "XAFilmingJobComparer.h"
#include <cassert>

using namespace std;

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


FilmingJobDispatcher::FilmingJobDispatcher(IXAFilmingCommunicationProxy* communicator) : _jobMap(), _communicator(communicator)
{
}


FilmingJobDispatcher::~FilmingJobDispatcher()
{
    for(auto iter = _jobMap.begin(); iter != _jobMap.end(); iter++)
    {
        auto job = iter->second;
        SAFE_DELETE_ELEMENT(job);
    }
    SAFE_DELETE_ELEMENT(_communicator);
}

void FilmingJobDispatcher::AddJob(XAFilmingJobBase* job)
{
    LOG_INFO_XA_FILMING << "Add a filming job" << LOG_END;
    _jobMap[job->GetJobID()] = job;
	job->SetFilmingProxy(_communicator);

    PushJobsProgress();
}

void FilmingJobDispatcher::ContinueJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Continue jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Continue);
    PushJobsProgress();
}

void FilmingJobDispatcher::DeleteJobs(const vector<int>& IDs)
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

void FilmingJobDispatcher::PauseJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Pause jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Pause);
    PushJobsProgress();
}

void FilmingJobDispatcher::RestartJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Restart jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
    XA_FILMING_JOB_MAP_DELEGATE(Restart);
    PushJobsProgress();
}

void FilmingJobDispatcher::UrgentJobs(const vector<int>& iDs)
{
    LOG_INFO_XA_FILMING << "Urgent jobs [" << serialize(iDs).c_str() << "]" << LOG_END;
    vector<int> IDs(iDs);
    reverse(IDs.begin(), IDs.end());
    XA_FILMING_JOB_MAP_DELEGATE(Urgent);
    PushJobsProgress();
}

void FilmingJobDispatcher::PushJobsProgress()
{
    auto jobs = GetSortedJobVector();
    
    if(!jobs.empty()) {jobs[0]->Film();}

    _communicator->PublishJobProgress(jobs);
}

void FilmingJobDispatcher::NofifyPrintStatus(bool bStatus)
{
	LOG_INFO_XA_FILMING << "Received Printed Message : Succeed? [" << bStatus << "]" << LOG_END;

    auto jobs = GetSortedJobVector();
    assert(!jobs.empty());

	auto job = jobs[0];
	bStatus ? job->Complete() : job->Fail();
    
    PushJobsProgress();
}

int FilmingJobDispatcher::GetEstimatedTimeToFinish()
{
	int time = 0;
	for (auto iter = _jobMap.begin(); iter != _jobMap.end(); iter++)
	{
		auto job = iter->second;
		time += job->GetEstimatedTimeToFinish();
	}
	return time;
}

vector<XAFilmingJobBase*> FilmingJobDispatcher::GetSortedJobVector()
{
    vector<XAFilmingJobBase*> jobs;
    for(auto iter = _jobMap.begin(); iter != _jobMap.end(); iter++)
    {
        jobs.push_back(iter->second);
    }

    XAFilmingJobComparer comparer;
    sort(jobs.begin(), jobs.end(), comparer);
    return jobs;
}
