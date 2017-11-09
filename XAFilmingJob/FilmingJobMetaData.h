#pragma once
#include "IFilmingJobMetaData.h"
#include <boost/thread/lock_types.hpp>

class FilmingJobMetaData : public IFilmingJobMetaData
{
public:
	FilmingJobMetaData(IStudyInfo& study_info)
	{
		_patientID = study_info.GetPatientID();
		_patientName = study_info.GetPatientName();

		//TODO: _createTime = Now;
	}

	virtual std::string GetPatientID() {return _patientID;}
	virtual std::string GetPatientName() {return _patientName;}
	virtual ~FilmingJobMetaData(){}
	virtual std::string GetJobCreateTime() {return _createTime;}
private:
	std::string _patientID;
	std::string _patientName;
	std::string _createTime;
};
