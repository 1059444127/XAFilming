#include "FilmDicomFileCommand.h"
#include "vector"
#include "XAFilmingSerializer.h"
#include "XAFilmingLogger.h"

void FilmDicomFileCommand::Excute(const string& serializedParameters)
{
	LOG_INFO_XA_FILMING << "FilmDicomFileCommand Executing, with parameter: [" << serializedParameters << "]" << LOG_END;
	vector<string> filePaths;
	deserializeStrings(serializedParameters, filePaths);

	_jobDispatcher->AddJob(nullptr);	//TODO: CreateFilmingJob;
}
