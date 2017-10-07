#include "XAFilmingJobDispatcher.h"
#include <XAFilmingLogger.h>
#include <XAFilmingSerializer.h>


XAFilmingJobDispatcher::XAFilmingJobDispatcher() : _jobQueue()
{
}


XAFilmingJobDispatcher::~XAFilmingJobDispatcher()
{
    while(!_jobQueue.empty())
    {
        auto job = _jobQueue.top();
        _jobQueue.pop();
        SAFE_DELETE_ELEMENT(job);
    }
}

void XAFilmingJobDispatcher::AddJob(XAFilmingJobBase* job)
{
}

void XAFilmingJobDispatcher::ContinueJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Continue jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
}

void XAFilmingJobDispatcher::DeleteJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Delete jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
}

void XAFilmingJobDispatcher::PauseJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Pause jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
}

void XAFilmingJobDispatcher::RestartJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Restart jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
}

void XAFilmingJobDispatcher::UrgentJobs(const vector<int>& IDs)
{
    LOG_INFO_XA_FILMING << "Urgent jobs [" << serialize(IDs).c_str() << "]" << LOG_END;
}

void XAFilmingJobDispatcher::PushJobsProgress()
{
}
