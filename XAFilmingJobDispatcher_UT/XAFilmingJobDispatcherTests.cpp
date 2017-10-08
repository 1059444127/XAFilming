#include "XAFilmingJobDispatcherTests.h"
#include "XAFilmingJobDispatcherFactory.h"

TEST_F(XAFilmingJobDispatcherTests, XAFilmingJobDispatcherFactory_Is_Singleton)
{
    auto factory1 = XAFilmingJobDispatcherFactory::Instance();
    auto factory2 = XAFilmingJobDispatcherFactory::Instance();

    EXPECT_EQ(factory2, factory1);
}

//TODO-Feature: When urgent job 2, 3, Then keep the priority order