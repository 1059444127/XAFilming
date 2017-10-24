#pragma once
#include "xafilmingjobcommandbase.h"
class FilmDicomDataheaderCommand :
	public XAFilmingJobCommandBase
{
public:
	virtual void Excute(const std::string& serializedParameters);
	virtual ~FilmDicomDataheaderCommand() {};
};

