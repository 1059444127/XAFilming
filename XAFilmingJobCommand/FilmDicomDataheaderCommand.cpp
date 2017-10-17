#include "FilmDicomDataheaderCommand.h"


void FilmDicomDataheaderCommand::SetJobDispatcher(IXAFilmingJobDispatch* jobDispatcher)
{
	_pJobDispatcher = jobDispatcher;
}

void FilmDicomDataheaderCommand::Excute(const std::string& serializedParameters)
{

}
