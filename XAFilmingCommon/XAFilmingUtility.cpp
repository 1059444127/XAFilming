#include "XAFilmingUtility.h"
#include "XAFilmingLogger.h"


void split(const string serializedString, const string separator, vector<string> & splitStringVector)
{
	LOG_INFO_XA_FILMING << "Spliting [" << serializedString << "] with separator [" << separator << "]" << LOG_END;

	size_t begin = 0;
	size_t end = serializedString.find(separator, begin);
		
	while(string::npos != end)
	{
		string item = serializedString.substr(begin, end-begin);
		splitStringVector.push_back(item);
		
		begin = end + separator.size();
		end = serializedString.find(separator, begin);
	}

	string lastItem = serializedString.substr(begin);
	splitStringVector.push_back(lastItem);
}

void join(const vector<string>& stringVector, const string separator, string& joinedString)
{
	LOG_INFO_XA_FILMING << "Joinning series with separator [" << separator << "]" << LOG_END;

	auto size = stringVector.size();
	if(size <= 0) {joinedString = XA_FILMING_EMPTY_STRING;  return;}

	auto iter = stringVector.begin();
	stringstream ss;
	ss << *iter++;
	for (; iter != stringVector.end(); ++iter)
	{
		ss << separator << *iter;
	}
	joinedString = ss.str();
}

void serializeStrings(const vector<string>& stringVector, string& serializedString)
{
	//TODO: Replace "|" with Definitions
	LOG_INFO_XA_FILMING << "serializing strings " << LOG_END;
	join(stringVector, "|", serializedString);
}

void deserializeStrings(const string serializedString, vector<string>& splitStringVector)
{
	LOG_INFO_XA_FILMING << "Deserializing [" << serializedString << "]" <<  LOG_END;
	split(serializedString, "|", splitStringVector);
}
