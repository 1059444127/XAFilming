#include "DataPacketHeaderTests.h"
#include "../XAFilmingJob/DataPacketHeader.h"

TEST_F(DataPacketHeaderTests, Serialize_From_Empty_String)
{
	DataPacketHeader header;
	header.DeserializeFrom(std::string());

	ASSERT_TRUE(std::string()==header.uid);
	ASSERT_TRUE(0==header.index);
	ASSERT_TRUE(0==header.total);
}


TEST_F(DataPacketHeaderTests, Serialize_From_Single_String)
{
	DataPacketHeader header;
	std::string expectedString("guid");
	header.DeserializeFrom(expectedString);

	ASSERT_TRUE(expectedString==header.uid);
	ASSERT_TRUE(0==header.index);
	ASSERT_TRUE(0==header.total);
}

TEST_F(DataPacketHeaderTests, Serialize_From_Two_String)
{
	DataPacketHeader header;
	std::string expectedString("guid|1");
	header.DeserializeFrom(expectedString);

	ASSERT_TRUE(std::string("guid")==header.uid);
	ASSERT_TRUE(1==header.index);
	ASSERT_TRUE(0==header.total);
}

