#pragma once
#include <string>
#include "IStudyInfo.h"

class IFilmingJobMetaData : public IStudyInfo
{
public:
	virtual ~IFilmingJobMetaData()	{}

	virtual std::string GetJobCreateTime() const = 0;

};

class NullFilmingJobMetaData : public IFilmingJobMetaData
{
public:
	virtual ~NullFilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() const {return std::string();}
	virtual std::string GetPatientID() const {return std::string();};
	virtual std::string GetPatientName() const {return std::string();}
};