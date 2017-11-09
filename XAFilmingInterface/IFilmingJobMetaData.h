#pragma once
#include <string>
#include "IStudyInfo.h"

class IFilmingJobMetaData : public IStudyInfo
{
public:
	virtual ~IFilmingJobMetaData()	{}

	virtual std::string GetJobCreateTime() = 0;

};

class NullFilmingJobMetaData : public IFilmingJobMetaData
{
public:
	virtual ~NullFilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() {return std::string();}
	virtual std::string GetPatientID() {return std::string();};
	virtual std::string GetPatientName() {return std::string();}
};