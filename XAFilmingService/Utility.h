#pragma once

#ifdef XA_FILMING_LIB
#define XA_Utility_LIB __declspec (dllexport)
#else //!defined(MCSF_BUILD_FILMING_DB_LIB)
#define XA_Utility_LIB __declspec (dllimport)
#endif

using namespace std;

#include <vector>

namespace StrUtil
{
	XA_Utility_LIB void split(const string serializedString, const string separator, vector<string> & splitStringVector);
}
