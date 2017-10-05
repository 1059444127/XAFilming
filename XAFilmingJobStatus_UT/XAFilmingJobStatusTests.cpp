#include "XAFilmingJobStatusTests.h"
#include "XAFilmingJobStatusFactory.h"


TEST_F(XAFilmingJobStatusTests, XAFilmingJobStatusFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobStatusFactory::Instance();
    auto factory2 = XAFilmingJobStatusFactory::Instance();
	EXPECT_EQ(factory1, factory2);
}


