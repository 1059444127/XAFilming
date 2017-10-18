#include "XAFilmingSerializerTests.h"
#include "XAFilmingMacro.h"
#include "XAFilmingSerializer.h"

using namespace std;

void Compare(const vector<string>& expectedStrings, const vector<string>& actualStrings)
{
	auto actualStringsCount = actualStrings.size();
	auto expectedStringsCount = expectedStrings.size();

	EXPECT_TRUE(0 == expectedStringsCount - actualStringsCount);

	for (int i=0; i<actualStringsCount; i++)
	{
		EXPECT_STREQ(expectedStrings[i].c_str(), actualStrings[i].c_str());
	}
}

TEST_F(XAFilmingSerializerTests, EmptyString_Serailize_and_Deserialize)
{
	// Preapare
	vector<string> actualStrings;
	vector<string> expectedStrings;

	actualStrings.push_back(XA_FILMING_EMPTY_STRING);
	string serializedString;

	// Act
	serializeStrings(actualStrings, serializedString);
	deserializeStrings(serializedString, expectedStrings);

	// Assert
	Compare(expectedStrings, actualStrings);
}

TEST_F(XAFilmingSerializerTests, OneString_Serailize_and_Deserialize)
{
		// Preapare
	vector<string> actualStrings;
	vector<string> expectedStrings;

	actualStrings.push_back("OneString");
	string serializedString;

	// Act
	serializeStrings(actualStrings, serializedString);
	deserializeStrings(serializedString, expectedStrings);

	// Assert
	Compare(expectedStrings, actualStrings);
}

TEST_F(XAFilmingSerializerTests, MultiString_Serailize_and_Deserialize)
{
		// Preapare
	vector<string> actualStrings;
	vector<string> expectedStrings;

	actualStrings.push_back("OneString");
	actualStrings.push_back("TwoString");
	string serializedString;

	// Act
	serializeStrings(actualStrings, serializedString);
	deserializeStrings(serializedString, expectedStrings);

	// Assert
	Compare(expectedStrings, actualStrings);
}

TEST_F(XAFilmingSerializerTests, String_To_Int)
{
	int expected = 32;
	string actualString = "32";

	int actual = string_to_int(actualString);

	EXPECT_TRUE(expected==actual);
}

TEST_F(XAFilmingSerializerTests, Int_To_String)
{
	string expected = "32";
	int actualInt = 32;

	string actual = int_to_string(actualInt);

	EXPECT_TRUE(expected==actual);
}


TEST_F(XAFilmingSerializerTests, True_To_String)
{
	string expected = "1";

	string actual = bool_to_string(true);
	
	EXPECT_TRUE(expected==actual);
}

TEST_F(XAFilmingSerializerTests, False_To_String)
{
	string expected = "0";

	string actual = bool_to_string(false);
	
	EXPECT_TRUE(expected==actual);
}


TEST_F(XAFilmingSerializerTests, String_1_To_True)
{
	bool expected = true;

	bool actual = string_to_bool("1");
	
	EXPECT_TRUE(expected==actual);
}


TEST_F(XAFilmingSerializerTests, String_Not_1_To_False)
{
	bool expected = false;

	bool actual = string_to_bool("11");
	
	EXPECT_TRUE(expected==actual);
}

TEST_F(XAFilmingSerializerTests, Double_To_Percentage)
{
	int expected = 33;
	int actual = double_to_percentage(1.0/3);

	EXPECT_TRUE(expected==actual);
}