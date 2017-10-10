#include "XAFilmingUtilityTests.h"
#include "XAFilmingMacro.h"
#include "XAFilmingSerializer.h"


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

TEST_F(XAFilmingUtilityTests, EmptyString_Serailize_and_Deserialize)
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

TEST_F(XAFilmingUtilityTests, OneString_Serailize_and_Deserialize)
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

TEST_F(XAFilmingUtilityTests, MultiString_Serailize_and_Deserialize)
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

TEST_F(XAFilmingUtilityTests, String_To_Int)
{
	int expected = 32;
	string actualString = "32";

	int actual = string_to_int(actualString);

	EXPECT_TRUE(expected==actual);
}