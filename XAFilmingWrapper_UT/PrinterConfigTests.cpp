#include "PrinterConfigTests.h"
#include "PrinterConfig.h"

using namespace std;

TEST_F(PrinterConfigTests, PrinterConfig_PrinterConfigStub)
{
    std::string printerConfigPath = "../../../../IAS/MiddleWare/Filming/XAFilmingWrapper_UT/PrinterConfigStub.xml";
	PrinterConfig printerConfig(printerConfigPath);
	printerConfig.ReadConfig();

	EXPECT_TRUE(printerConfig.GetAE()=="FooAE");
	EXPECT_TRUE(printerConfig.GetIP()==string("8.8.8.8"));
	EXPECT_TRUE(printerConfig.GetFilmSize()==string("8INX10IN"));
	EXPECT_TRUE(printerConfig.ReadConfigBeforeUsing()==false);
	EXPECT_TRUE(printerConfig.GetPort()==60001);
}