#pragma once

#include <IFilmingJobMetaData.h>
#include <vector>

class IFilmingJobBuilder: public IFilmingJobMetaData
{
public:
	virtual void AddDicomFile(const std::string dicomFilePath) = 0;
	virtual void AddSopInstanceUid(const std::string& sopInstanceUid) = 0;
	virtual bool IsComplete() const = 0;
	virtual std::vector<std::string> GetDicomFiles() = 0;
};
