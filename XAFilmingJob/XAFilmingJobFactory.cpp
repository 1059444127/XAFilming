#include "XAFilmingJobFactory.h"
#include "XAJob.h"
#include "FilmingJob.h"
#include <XAFilmingLogger.h>
#include "XADicom.h"

using namespace std;

XAFilmingJobFactory* XAFilmingJobFactory::_instance = new XAFilmingJobFactory();
int XAFilmingJobFactory::_maxJobID = 0; //TODO; Get Max JobID From DB ,write in XAFilmingWrapper

XAFilmingJobFactory* XAFilmingJobFactory::Instance()
{
    return _instance;
}

XAFilmingJobBase* XAFilmingJobFactory::CreateJob()
{
    return new XAJob(++_maxJobID);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(vector<string> dicomFiles)
{
    return new FilmingJob(++_maxJobID, dicomFiles);
}

XAFilmingJobBase* XAFilmingJobFactory::CreateFilmingJob(std::string serializedDataheader)
{
	string dicomFilePath;

	if(!SaveStringToDicomFile(serializedDataheader, dicomFilePath))
	{
		LOG_ERROR_XA_FILMING << "Failed to save serialized DataHeader to dicom file , printing failed" << LOG_END;
	}


	vector<string> filePaths;  filePaths.push_back(dicomFilePath);
	auto job = CreateFilmingJob(filePaths);

	return job;
}
