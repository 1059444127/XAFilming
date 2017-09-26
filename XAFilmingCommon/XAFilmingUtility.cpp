#include "XAFilmingUtility.h"

	void split(const string serializedString, const string separator, vector<string> & splitStringVector)
	{
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

void join(const vector<string> stringVector, const string separator, string& joinedString)
{
}
