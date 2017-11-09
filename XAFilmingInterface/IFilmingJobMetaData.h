#pragma once
#include <string>

class IFilmingJobMetaData
{
public:
	virtual ~IFilmingJobMetaData()	{}

	virtual std::string GetJobCreateTime() = 0;
	virtual std::string GetPatientID() = 0;
	virtual std::string GetPatientName() = 0;
};

class NullFilmingJobMetaData : public IFilmingJobMetaData
{
public:
	virtual ~NullFilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() {return std::string();}
	virtual std::string GetPatientID() {return std::string();};
	virtual std::string GetPatientName() {return std::string();}
};