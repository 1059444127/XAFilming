#include "XAFilmingJobCommandFactory.h"

#include "XAFilmingJobCommandTests.h"

TEST_F(XAFilmingJobCommandTests, XAFilmingJobCommandFactory_Is_Singleton)
{
	auto pJobCommandFactory1 = XAFilmingJobCommandFactory::GetInstance();
	auto pJobCommandFactory2=  XAFilmingJobCommandFactory::GetInstance();

	EXPECT_TRUE(pJobCommandFactory2==pJobCommandFactory1);
}


