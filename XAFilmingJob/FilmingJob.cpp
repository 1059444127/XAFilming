#include "FilmingJob.h"
#include "XAFilmingJobStatusFactory.h"


FilmingJob::FilmingJob(int ID) : XAFilmingJobBase(XAFilmingJobStatusFactory::Instance()->CreateJobStatus()), _iID(ID)
{
}

int FilmingJob::GetJobID()
{
    return _iID;
}
