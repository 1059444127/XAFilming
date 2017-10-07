#include "XAFilmingInterfaceTests.h"

#include <ctime>

#include "JobMock.h"
#include "JobStatusMock.h"
#include "XAFilmingJobComparer.h"

TEST_F(XAFilmingInterfaceTests, Job_Status_Priority)
{
    srand((unsigned int)time(0));

    auto printing = new JobStatusMock(Printing);
    auto waiting = new JobStatusMock(Waiting);
    auto paused= new JobStatusMock(Paused);
    auto done = new JobStatusMock(Done);
    auto fail = new JobStatusMock(Failed);

    JobMock printingJob(printing, rand(), rand());
    JobMock waitingJob(waiting, rand(), rand());
    JobMock pausedJob(paused, rand(), rand());
    JobMock doneJob(done, rand(), rand());
    JobMock failJob(fail, rand(), rand());
    
    XAFilmingJobComparer comparer;

    EXPECT_TRUE(comparer(&printingJob, &waitingJob));
    EXPECT_TRUE(comparer(&waitingJob, &pausedJob));
    EXPECT_TRUE(comparer(&pausedJob, &failJob));
    EXPECT_TRUE(comparer(&failJob, &doneJob));
    EXPECT_FALSE(comparer(&doneJob, &printingJob));
}

TEST_F(XAFilmingInterfaceTests, Job_Priority)
{
    srand((unsigned int)time(0));
    JobMock job1(new JobStatusMock(Waiting), rand(), 5);
    JobMock job2(new JobStatusMock(Waiting), rand(), 3);
    JobMock job3(new JobStatusMock(Waiting), rand(), 4);

    XAFilmingJobComparer comparer;
    
    EXPECT_TRUE(comparer(&job1, &job2));
    EXPECT_FALSE(comparer(&job2, &job3));
}

TEST_F(XAFilmingInterfaceTests, Job_ID_Priority)
{
    JobMock job1(new JobStatusMock(Paused), 1, 1);
    JobMock job2(new JobStatusMock(Paused), 3, 1);
    JobMock job3(new JobStatusMock(Paused), 2, 1);

    XAFilmingJobComparer comparer;
    
    EXPECT_TRUE(comparer(&job1, &job2));
    EXPECT_FALSE(comparer(&job2, &job3));
    
}