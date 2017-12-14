#pragma once
#include "IStudyInfo.h"
#include <set>

class IFilmingJobMetaData : public IStudyInfo
{
public:
	virtual ~IFilmingJobMetaData()	{}

	virtual const std::set<const std::string>& GetSopInstanceUids() const = 0;

	virtual std::string GetJobCreateTime() const = 0;

};

class NullFilmingJobMetaData : public IFilmingJobMetaData
{
public:
	virtual ~NullFilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() const {return std::string();}
	virtual std::string GetPatientID() const {return std::string();};
	virtual std::string GetPatientName() const {return std::string();}
	virtual std::string GetStudyInstanceUid() const {return std::string();}
	virtual const std::set<const std::string>& GetSopInstanceUids() const {return _sopInstanceUids;}
private:
	std::set<const std::string> _sopInstanceUids;

};
