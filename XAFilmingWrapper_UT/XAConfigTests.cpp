#include "XAConfigTests.h"
#include "XAConfig.h"
#include "boost/filesystem.hpp"
#include "XAFilmingConst.h"

TEST_F(XAConfigTests, XAConfig_Is_A_Singleton)
{
	auto config1 = XAConfig::Instance();
	auto config2 = XAConfig::Instance();

	ASSERT_TRUE(config1==config2);
}

TEST_F(XAConfigTests, PrinterConfigPath_Is_Correct)
{
	boost::filesystem::path expectedPath(std::string("../appdata/XA/Filming/config/")+XA_PRINT_CONFIG_FILE_NAME);
	boost::filesystem::path actualPath(XAConfig::Instance()->GetPrinterConfigPath());

	//ASSERT_TRUE(boost::filesystem::equivalent(actualPath, expectedPath));
}