#include "FilmingJob.h"
#include "XAFilmingJobStatusFactory.h"
#include "XAFilmingLogger.h"
#include "XAFilmingConst.h"

int FilmingJob::MaxPriority = XA_Filming_Job_Min_Priority;

FilmingJob::FilmingJob(int ID) : XAFilmingJobBase(XAFilmingJobStatusFactory::Instance()->CreateJobStatus()), _iID(ID), _iPriority(XA_Filming_Job_Min_Priority)
{
}

int FilmingJob::GetJobID()
{
    return _iID;
}

void FilmingJob::Urgent()
{
    LOG_INFO_XA_FILMING << "Urgent Job [" << _iID << "] with Priority [" << _iPriority  << "]" << LOG_END;
    _iPriority = ++MaxPriority;
    LOG_INFO_XA_FILMING << "Promote to Priority [" << _iPriority << "]" << LOG_END;
}

int FilmingJob::GetPriority()
{
    return _iPriority;
}
