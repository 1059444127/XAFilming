#include "stdafx.h"
#include "UtilityTest.h"
#include "Utility.h"

using namespace StrUtil;

TEST_F(UtilityTest, Split_Empty_SerializedString_Get_Empty_String_Vector)
{

	//Arrange
	vector<string> stringVector;

	//Act
	split("", "|", stringVector);
	int expectedStringVectorSize = (int)stringVector.size();

	//Assert
	EXPECT_FALSE(expectedStringVectorSize-1);
}

TEST_F(UtilityTest, Split_String)
{
	//Arrange
	string string0 = " 123 ";
	string string1 = " ABC ";
	string serializedString = string0 + "|" + string1;
	vector<string> stringVector;

	//Act
	split(serializedString, "|", stringVector);
	int expectedStringVectorSize = (int)stringVector.size();

	//Assert
	EXPECT_FALSE(expectedStringVectorSize-2);
	EXPECT_STREQ(string0.c_str(), stringVector[0].c_str());
	EXPECT_STREQ(string1.c_str(), stringVector[1].c_str());
}