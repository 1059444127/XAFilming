#include "JobMock.h"
#include "XAFilmingJobStatusFactory.h"


JobMock::JobMock(): XAFilmingJobBase(XAFilmingJobStatusFactory::Instance()->CreateJobStatus())
{

}

int JobMock::GetJobID()
{
    return 0;
}



