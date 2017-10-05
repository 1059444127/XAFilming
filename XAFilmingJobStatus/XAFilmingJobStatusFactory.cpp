#include "XAFilmingJobStatusFactory.h"
#include "XAWaiting.h"

XAFilmingJobStatusFactory* XAFilmingJobStatusFactory::_instance = new XAFilmingJobStatusFactory();

XAFilmingJobStatusFactory* XAFilmingJobStatusFactory::Instance()
{
    return _instance;
}

const XAFilmingJobStatusBase* XAFilmingJobStatusFactory::CreateJobStatus()
{
    return new XAWaiting();
}




