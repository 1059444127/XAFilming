#pragma once
#include "IXAFilming.h"

class XAFilmingMock : public IXAFilming
{
public:
	virtual void Print(const std::vector<std::string>& filePaths) {}
	virtual void UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData) {}
};
 
