#pragma once
#include "BatchPrintJob.h"

class FilmingJob : public BatchPrintJob
{
public:

	FilmingJob(int ID, const std::vector<std::string>& dicomFiles, IFilmingJobMetaData* p_filming_job_meta_data)
		: BatchPrintJob(ID, dicomFiles), _pFilmingJobMetaData(p_filming_job_meta_data)
	{
	}

	virtual ~FilmingJob() {SAFE_DELETE_ELEMENT(_pFilmingJobMetaData);}

	virtual IFilmingJobMetaData* GetMetaData(){return _pFilmingJobMetaData;}

private:
	IFilmingJobMetaData* _pFilmingJobMetaData;
};
