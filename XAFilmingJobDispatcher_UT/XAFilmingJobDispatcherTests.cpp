#include "XAFilmingJobDispatcherTests.h"
#include "XAFilmingJobDispatcherFactory.h"

TEST_F(XAFilmingJobDispatcherTests, XAFilmingJobDispatcherFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobDispatcherFactory::Instance();
    auto factory2 = XAFilmingJobDispatcherFactory::Instance();

    EXPECT_TRUE(factory2==factory1);
}

