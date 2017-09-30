#include "XAFilmingJobCommandFactory.h"

#include "XAFilmingJobCommandFactoryTests.h"

TEST_F(XAFilmingJobCommandFactoryTests, XAFilmingJobCommandFactory_Is_Singleton)
{
	auto pJobCommandFactory1 = XAFilmingJobCommandFactory::GetInstance();
	auto pJobCommandFactory2=  XAFilmingJobCommandFactory::GetInstance();

	EXPECT_TRUE(pJobCommandFactory2==pJobCommandFactory1);
}


