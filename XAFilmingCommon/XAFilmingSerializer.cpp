#include "XAFilmingSerializer.h"
#include "XAFilmingLogger.h"

#include "CommunicationCommandID.h"
#include <sstream>



template<class T>
string serialize(const vector<T>& collection, const string& separator)
{
    auto size = collection.size();
    if(size <= 0) {return XA_FILMING_EMPTY_STRING;}

	auto iter = collection.begin();
	stringstream ss;
	ss << *iter++;
	for (; iter != collection.end(); ++iter)
	{
		ss << separator << *iter;
	}
	return ss.str();;
}

template<class T>
string serialize(const vector<T>& collection)
{
    return serialize<T>(collection, PARAMETER_LIST_SEPARATOR);
}

void split(const string serializedString, const string& separator, vector<string> & splitStringVector)
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

void join(const vector<string>& stringVector, const string& separator, string& joinedString)
{
	LOG_INFO_XA_FILMING << "Joinning series with separator [" << separator << "]" << LOG_END;

    joinedString = serialize<string>(stringVector, separator);
}

void serializeStrings(const vector<string>& stringVector, string& serializedString)
{
	LOG_INFO_XA_FILMING << "serializing strings " << LOG_END;
	join(stringVector, PARAMETER_LIST_SEPARATOR, serializedString);
}

void deserializeStrings(const string serializedString, vector<string>& splitStringVector)
{
	LOG_INFO_XA_FILMING << "Deserializing [" << serializedString << "]" <<  LOG_END;
	split(serializedString, PARAMETER_LIST_SEPARATOR, splitStringVector);
}


