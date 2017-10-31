#include "FilmingJobTests.h"
#include <XAFilmingJobFactory.h>

using namespace std;

void FilmingJobTests::SetUp()
{
	auto factory = XAFilmingJobFactory::Instance();
	_job = factory->CreateFilmingJob(_filePaths);
	_job->SetFilmingProxy(_filmingProxy);
}

void FilmingJobTests::TearDown()
{
	SAFE_DELETE_ELEMENT(_job);
}

TEST_F(FilmingJobTests, New_Filming_Job_Is_Waiting)
{
	auto jobStatus = _job->GetJobStatus();
	EXPECT_TRUE(XAFilmingJobStatusEnum::Waiting == jobStatus->GetStatusPriority());
}

TEST_F(FilmingJobTests, New_Filming_Job_Finished_is_0)
{
	EXPECT_TRUE(0==_job->GetFinished());
}

TEST_F(FilmingJobTests, Printing_A_New_Filming_Job_Finished_is_0)
{
	_job->Film();
	EXPECT_TRUE(0==_job->GetFinished());
}

TEST_F(FilmingJobTests, Estimate_Time_Of_A_New_Filming_Job_With_Files_GT_0)
{
	EXPECT_TRUE(_job->GetEstimatedTimeToFinish()>0);
}
