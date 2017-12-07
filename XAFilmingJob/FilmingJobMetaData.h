#pragma once
#include "IFilmingJobMetaData.h"
#include <boost/thread/lock_types.hpp>
#include "XABoost.h"

class FilmingJobMetaData : public IFilmingJobMetaData
{
public:
	FilmingJobMetaData(const IStudyInfo& study_info)
	{
		_patientID = study_info.GetPatientID();
		_patientName = study_info.GetPatientName();

		_createTime = XANow();
	}

	virtual std::string GetPatientID() const {return _patientID;}
	virtual std::string GetPatientName() const {return _patientName;}
	virtual ~FilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() const {return _createTime;}
private:
	std::string _patientID;
	std::string _patientName;
	std::string _createTime;
};
