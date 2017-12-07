#pragma once
#include <string>

class IStudyInfo
{
public:
	virtual std::string GetPatientID() const = 0;
	virtual std::string GetPatientName() const = 0;
};
