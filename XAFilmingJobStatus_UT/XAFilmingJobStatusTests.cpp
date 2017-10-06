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


TEST_F(XAFilmingJobStatusTests, Pause_And_Continue_Print_Fail_Restart_Print_Complete_Restart_Print_A_Job)
{
    auto pJob = new JobMock();
    auto pStatusExpectWaiting = XAFilmingJobStatusFactory::Instance()->CreateJobStatus();
    
    pStatusExpectWaiting->Pause(pJob);
    SAFE_DELETE_ELEMENT(pStatusExpectWaiting)
    auto pStatusExpectPaused = pJob->GetJobStatus();  
    EXPECT_EQ(XA_Filming_Job_Paused, pStatusExpectPaused->ToString());

    pStatusExpectPaused->Continue(pJob);
    auto pStatusWaiting = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Waiting, pStatusWaiting->ToString());

    pStatusWaiting->Print(pJob);
    auto pStatusPrinting = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Printing, pStatusPrinting->ToString());

    pStatusPrinting->Fail(pJob);
    auto pStatusFailed = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Failed, pStatusFailed->ToString());

    pStatusFailed->Restart(pJob);
    auto pStatusWaiting2 = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Waiting, pStatusWaiting2->ToString());

    pStatusWaiting2->Print(pJob);
    pJob->GetJobStatus()->Complete(pJob);
    auto pStatusDone = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Done, pStatusDone->ToString());

    pStatusDone->Restart(pJob);
    auto pStatusWaiting3 = pJob->GetJobStatus();
    EXPECT_EQ(XA_Filming_Job_Waiting, pStatusWaiting3->ToString());


    SAFE_DELETE_ELEMENT(pJob);
}