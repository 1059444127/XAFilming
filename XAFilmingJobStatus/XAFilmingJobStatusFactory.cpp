#include "XAFilmingJobStatusFactory.h"
#include "XAWaiting.h"

XAFilmingJobStatusFactory* XAFilmingJobStatusFactory::_instance = new XAFilmingJobStatusFactory();

XAFilmingJobStatusFactory* XAFilmingJobStatusFactory::Instance()
{
    return _instance;
}

XAFilmingJobStatusBase* XAFilmingJobStatusFactory::CreateJobStatus()
{
    return new XAWaiting();
}




