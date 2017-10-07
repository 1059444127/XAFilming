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
    
    SAFE_DELETE_ELEMENT(job1)
    SAFE_DELETE_ELEMENT(job2)

    EXPECT_GT(job2ID, job1ID);
}

TEST_F(XAFilmingJobTests, Urgent_Job_with_High_Priority)
{
    auto factory = XAFilmingJobFactory::Instance();
    auto job1 = factory->CreateJob();
    auto job2 = factory->CreateJob();  
    
    job1->Urgent();
    job2->Urgent();

    auto job1Priority = job1->GetPriority();
    auto job2Priority = job2->GetPriority();

    SAFE_DELETE_ELEMENT(job1);
    SAFE_DELETE_ELEMENT(job2);

    EXPECT_GT(job2Priority, job1Priority);
}

//TODO-Feature; When Job done , job Priority return to min