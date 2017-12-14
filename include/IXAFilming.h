#pragma once
#include <vector>
#include "IFilmingJobMetaData.h"

class IXAFilming
{
public:
	virtual ~IXAFilming()	{	}

	virtual void Print(const std::vector<std::string>& filePaths) = 0;

	virtual void UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData) = 0;
};
