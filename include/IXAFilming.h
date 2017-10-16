#pragma once
#include <vector>

class IXAFilming
{
public:
	virtual ~IXAFilming()	{	}

	virtual void Print(const std::vector<std::string>& filePaths) = 0;
};
