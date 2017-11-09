#include "FilmDicomDataheaderCommand.h"
#include <XAFilmingLogger.h>
#include <XAFilmingJobFactory.h>

using namespace std;

void FilmDicomDataheaderCommand::Excute(const std::string& serializedParameters)
{
	auto job = XAFilmingJobFactory::Instance()->CreateFilmingJob(serializedParameters);
	if(nullptr != job) {_jobDispatcher->AddJob(job);}	
	
}
