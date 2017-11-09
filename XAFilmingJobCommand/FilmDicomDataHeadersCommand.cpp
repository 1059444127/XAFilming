#include "FilmDicomDataheadersCommand.h"
#include <XAFilmingLogger.h>
#include <XAFilmingJobFactory.h>

using namespace std;

void FilmDicomDataheadersCommand::Excute(const std::string& serializedParameters)
{

	auto job = XAFilmingJobFactory::Instance()->BuildFilmingJob(serializedParameters);
	if(nullptr == job)
	{
		LOG_INFO_XA_FILMING << "Waiting for batch dataHeaders complete" << LOG_END;
	}
	else
	{
		LOG_INFO_XA_FILMING << "Batch DataHeaders complete" << LOG_END;
		_jobDispatcher->AddJob(job);			
	}
	
}
