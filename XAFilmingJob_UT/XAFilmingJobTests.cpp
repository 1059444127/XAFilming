#include "XAFilmingJobTests.h"
#include "XAFilmingJobFactory.h"


TEST_F(XAFilmingJobTests, XAFilmingJobFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobFactory::Instance();
    auto factory2 = XAFilmingJobFactory::Instance();
	EXPECT_EQ(factory2, factory1);
}

TEST_F(XAFilmingJobTests, Job_ID_Ascending)
{
    auto factory = XAFilmingJobFactory::Instance();
    auto job1 = factory->CreateJob();
    auto job2 = factory->CreateJob();
    auto job1ID = job1->GetJobID();
    auto job2ID = job2->GetJobID();
    
    EXPECT_GT(job2ID, job1ID);
}