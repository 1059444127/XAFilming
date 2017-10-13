#include "FilmDicomFileCommand.h"
#include "vector"
#include "XAFilmingSerializer.h"
#include "XAFilmingLogger.h"
#include <XAFilmingJobFactory.h>

using namespace std;

void FilmDicomFileCommand::Excute(const string& serializedParameters)
{
	LOG_INFO_XA_FILMING << "FilmDicomFileCommand Executing, with parameter: [" << serializedParameters << "]" << LOG_END;
	vector<string> filePaths;
	deserializeStrings(serializedParameters, filePaths);

	auto job = XAFilmingJobFactory::Instance()->CreateFilmingJob(filePaths);
	_jobDispatcher->AddJob(job);	
}
