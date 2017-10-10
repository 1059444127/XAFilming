#pragma once
#include <vector>

class IXAFilming
{
public:
	virtual void Print(const std::vector<std::string>& filePaths) = 0;
};
