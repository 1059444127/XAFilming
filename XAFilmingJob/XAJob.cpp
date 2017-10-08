#include "XAJob.h"
#include "XAFilmingJobStatusFactory.h"
#include "XAFilmingLogger.h"
#include "XAFilmingConst.h"

int XAJob::MaxPriority = XA_Filming_Job_Min_Priority;

XAJob::XAJob(int ID) : XAFilmingJobBase(XAFilmingJobStatusFactory::Instance()->CreateJobStatus()), _iID(ID), _iPriority(XA_Filming_Job_Min_Priority)
{
}

int XAJob::GetJobID()
{
    return _iID;
}

void XAJob::ResetPriority()
{
    if(_iPriority > XA_Filming_Job_Min_Priority) 
    { --MaxPriority;}
    
    _iPriority = XA_Filming_Job_Min_Priority;
}

int XAJob::GetPriority()
{
    return _iPriority;
}

void XAJob::TopPriority()
{
    LOG_INFO_XA_FILMING << "Urgent Job [" << _iID << "] with Priority [" << _iPriority  << "]" << LOG_END;
    _iPriority = ++MaxPriority;
    LOG_INFO_XA_FILMING << "Promote to Priority [" << _iPriority << "]" << LOG_END;
}

std::string XAJob::GetProgress()
{
    return std::string();
}
