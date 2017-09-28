#include "XAFilmingUtilityTests.h"
#include "XAFilmingMacro.h"
#include "XAFilmingUtility.h"


void Compare(const vector<string>& expectedStrings, const vector<string>& actualStrings)
{
	auto actualStringsCount = actualStrings.size();
	auto expectedStringsCount = expectedStrings.size();

	EXPECT_EQ(expectedStringsCount, actualStringsCount);

	for (int i=0; i<actualStringsCount; i++)
	{
		EXPECT_EQ(expectedStrings[i], actualStrings[i]);
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

	//TODO: Import serialize funcitons from project XAFilmingCommon
	serializeStrings(actualStrings, serializedString);
	deserializeStrings(serializedString, expectedStrings);

	// Assert
	Compare(expectedStrings, actualStrings);
}