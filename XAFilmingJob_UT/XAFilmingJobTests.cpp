#include "XAFilmingJobTests.h"
#include "XAFilmingJobFactory.h"


TEST_F(XAFilmingJobTests, XAFilmingJobFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobFactory::Instance();
    auto factory2 = XAFilmingJobFactory::Instance();
	EXPECT_EQ(factory2, factory1);
}
