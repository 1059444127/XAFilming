#include "TestConfigTests.h"
#include "TestConfig.h"

TEST_F(TestConfigTests, No_Config_No_Delay)
{
	std::string testConfigPath = "";
	TestConfig testConfig(testConfigPath);
	testConfig.ReadConfig();

	EXPECT_FALSE(testConfig.GetToDelayJob());
	EXPECT_TRUE(testConfig.GetDelaySeconds()==0);

}


TEST_F(TestConfigTests, Sample_Config_With_Delay)
{
	std::string testConfigPath = "../../../../IAS/MiddleWare/Filming/XAFilmingWrapper_UT/TestConfigStub.xml";
	TestConfig testConfig(testConfigPath);
	testConfig.ReadConfig();

	EXPECT_TRUE(testConfig.GetToDelayJob());
	EXPECT_TRUE(testConfig.GetDelaySeconds()==10);

}