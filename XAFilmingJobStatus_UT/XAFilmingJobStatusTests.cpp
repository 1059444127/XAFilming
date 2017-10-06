#include "XAFilmingJobStatusTests.h"
#include "XAFilmingJobStatusFactory.h"
#include "XAFilmingConst.h"
#include "JobMock.h"


TEST_F(XAFilmingJobStatusTests, XAFilmingJobStatusFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobStatusFactory::Instance();
    auto factory2 = XAFilmingJobStatusFactory::Instance();
    EXPECT_EQ(factory1, factory2);
}


TEST_F(XAFilmingJobStatusTests, Pause_And_Continue_A_Job)
{
    auto pJob = new JobMock();
    auto pStatusExpectWaiting = XAFilmingJobStatusFactory::Instance()->CreateJobStatus();
    
    pStatusExpectWaiting->Pause(pJob);
    SAFE_DELETE_ELEMENT(pStatusExpectWaiting)
    auto pStatusExpectPaused = pJob->GetJobStatus();  
    EXPECT_EQ(XA_Filming_Job_Paused, pStatusExpectPaused->ToString());

    pStatusExpectPaused->Continue(pJob);
    auto pStatusActual = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Waiting, pStatusActual->ToString());
}