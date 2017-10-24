#pragma once
#include "IXAFilming.h"

class XAFilmingMock : public IXAFilming
{
public:
	virtual void Print(const std::vector<std::string>& filePaths) {}
};
 
