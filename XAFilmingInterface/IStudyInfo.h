#pragma once
#include <string>

class IStudyInfo
{
public:
	virtual std::string GetPatientID() = 0;
	virtual std::string GetPatientName() = 0;
};
