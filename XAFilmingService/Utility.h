#pragma once

#ifdef XA_FILMING_LIB
#define XA_Utility_LIB __declspec (dllexport)
#else //!defined(MCSF_BUILD_FILMING_DB_LIB)
#define XA_Utility_LIB __declspec (dllimport)
#endif


#include <vector>

namespace StrUtil
{
	XA_Utility_LIB void split(const std::string serializedString, const std::string separator, std::vector<std::string> & splitStringVector);
}
