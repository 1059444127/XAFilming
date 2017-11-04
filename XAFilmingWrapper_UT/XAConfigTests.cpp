#include "XAConfigTests.h"
#include "XAConfig.h"

TEST_F(XAConfigTests, XAConfig_Is_A_Singleton)
{
	auto config1 = XAConfig::Instance();
	auto config2 = XAConfig::Instance();

	ASSERT_TRUE(config1==config2);
}