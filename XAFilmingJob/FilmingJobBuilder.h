#pragma once
#include "FilmingJobMetaData.h"
#include <vector>
#include <XAFilmingLogger.h>

class FilmingJobBuilder : public FilmingJobMetaData
{
public:
	FilmingJobBuilder(const IStudyInfo& study_info, int expectedFileCount)
		: FilmingJobMetaData(study_info), _dicomFiles(), _expectedFileCount(expectedFileCount), _currentFileCount(0), _isComplete(false)
	{
	}

	void AddDicomFile(const std::string dicomFilePath)
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

	bool IsComplete() const
	{
		return _isComplete;
	}

	std::vector<std::string> GetDicomFiles()
	{
		return _dicomFiles;
	}

private:
	std::vector<std::string> _dicomFiles;
	int _currentFileCount;
	bool _isComplete;
	const int _expectedFileCount;
};
