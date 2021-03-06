#pragma once
#include <vector>
#include <XAFilmingLogger.h>
#include "IFilmingJobBuilder.h"
#include "XABoost.h"

class FilmingJobBuilder : public IFilmingJobBuilder
{
public:
	FilmingJobBuilder(const IStudyInfo& study_info, int expectedFileCount)
		: _dicomFiles(), _expectedFileCount(expectedFileCount), _currentFileCount(0), _isComplete(false), _sopInstanceUids()
	{
		_patientID = study_info.GetPatientID();
		_patientName = study_info.GetPatientName();
		_studyInstanceUid = study_info.GetStudyInstanceUid();
		_createTime = XANow();
	}

	virtual std::string GetPatientID() const {return _patientID;}

	virtual std::string GetPatientName() const  {return _patientName;}

	virtual std::string GetJobCreateTime() const {return _createTime;}

	virtual void AddDicomFile(const std::string dicomFilePath)
	{
		LOG_INFO_XA_FILMING << "Add dicom File " << dicomFilePath << LOG_END;
		_dicomFiles.push_back(dicomFilePath);
		_currentFileCount++;
		LOG_INFO_XA_FILMING << "Current File Count: [" << _currentFileCount << "], Expected File Count: " << _expectedFileCount << "]" << LOG_END;
		if(_currentFileCount >= _expectedFileCount)
		{
			LOG_INFO_XA_FILMING << "Job Complete" << LOG_END;
			_isComplete = true;
		}
		
	}

	virtual bool IsComplete() const
	{
		return _isComplete;
	}

	//TODO: const && * for GetDicomFiles
	virtual std::vector<std::string> GetDicomFiles()
	{
		return _dicomFiles;
	}

	virtual std::string GetStudyInstanceUid() const {return _studyInstanceUid;}
	virtual const std::set<const std::string>& GetSopInstanceUids() const {return _sopInstanceUids;}
	virtual void AddSopInstanceUid(const std::string& sopInstanceUid) {_sopInstanceUids.insert(sopInstanceUid);}
private:
	std::vector<std::string> _dicomFiles;
	int _currentFileCount;
	bool _isComplete;
	const int _expectedFileCount;
	std::string _patientID;
	std::string _patientName;
	std::string _createTime;
	std::set<const std::string> _sopInstanceUids;
	std::string _studyInstanceUid;
	
};
