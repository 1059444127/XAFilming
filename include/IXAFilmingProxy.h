#pragma once
#include <vector>

class IXAFilmingProxy
{
	virtual void Print(const std::vector<std::string>& filePaths) = 0;
};
