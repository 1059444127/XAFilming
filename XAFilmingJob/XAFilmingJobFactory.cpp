#include "XAFilmingJobFactory.h"
#include "FilmingJob.h"

XAFilmingJobFactory* XAFilmingJobFactory::_instance = new XAFilmingJobFactory();
int XAFilmingJobFactory::_maxJobID = 1; //TODO; Get Max JobID From DB ,write in XAFilmingWrapper

XAFilmingJobFactory* XAFilmingJobFactory::Instance()
{
    return _instance;
}

XAFilmingJobBase* XAFilmingJobFactory::CreateJob()
{
    return new FilmingJob(++_maxJobID);
}
