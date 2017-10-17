#pragma once
#include "xafilmingjobcommandbase.h"
class FilmDicomDataheaderCommand :
	public XAFilmingJobCommandBase
{
public:

	virtual void SetJobDispatcher(IXAFilmingJobDispatch* jobDispatcher);
	virtual void Excute(const std::string& serializedParameters);
	virtual ~FilmDicomDataheaderCommand() {};

private:
	IXAFilmingJobDispatch* _pJobDispatcher;
};

