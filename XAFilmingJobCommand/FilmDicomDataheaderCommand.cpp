#include "FilmDicomDataheaderCommand.h"
#include "XADicom.h"
#include <XAFilmingLogger.h>
#include <XAFilmingJobFactory.h>

using namespace std;

void FilmDicomDataheaderCommand::SetJobDispatcher(IXAFilmingJobDispatch* jobDispatcher)
{
	_pJobDispatcher = jobDispatcher;
}

void FilmDicomDataheaderCommand::Excute(const std::string& serializedParameters)
{
	string dicomFilePath;

	if(!SaveStringToDicomFile(serializedParameters, dicomFilePath))
	{
		LOG_INFO_XA_FILMING << "Failed to save serialized DataHeader to dicom file , printing failed" << LOG_END;
		return;
	}

	vector<string> filePaths;  filePaths.push_back(dicomFilePath);
	auto job = XAFilmingJobFactory::Instance()->CreateFilmingJob(filePaths);
	_jobDispatcher->AddJob(job);	
	
}
