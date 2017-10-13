#include "XAFilmingJobFactory.h"
#include "XAJob.h"
#include "FilmingJob.h"

using namespace std;

XAFilmingJobFactory* XAFilmingJobFactory::_instance = new XAFilmingJobFactory();
int XAFilmingJobFactory::_maxJobID = 0; //TODO; Get Max JobID From DB ,write in XAFilmingWrapper

XAFilmingJobFactory* XAFilmingJobFactory::Instance()
{
    return _instance;
}

XAFilmingJobBase* XAFilmingJobFactory::CreateJob()
{
    return new XAJob(++_maxJobID);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(vector<string> dicomFiles)
{
    return new FilmingJob(++_maxJobID, dicomFiles);
}
