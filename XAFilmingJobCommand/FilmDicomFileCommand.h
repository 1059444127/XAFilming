#pragma once
#include "xafilmingjobcommandbase.h"
class FilmDicomFileCommand :
	public XAFilmingJobCommandBase
{
public:

	virtual void Excute(const string& serializedParameters);
};

