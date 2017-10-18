#include "FilmingJob.h"
#include <sstream>
#include "XAFilmingLogger.h"


FilmingJob::FilmingJob(int ID, vector<string> dicomFiles) : XAJob(ID), _files(dicomFiles), _iProgress(0), _iFinished(0)
{

}

void FilmingJob::Complete()
{
    if (_iProgress < _files.size())
    {
		vector<string> filesToBePrinted = GetDicomFilsToPrint();
		Print(filesToBePrinted);
	    _iProgress++;
		_iFinished = _iProgress - 1;
    }

    else 
	{
		_iFinished ++;
		XAJob::Complete();
	}

}

double FilmingJob::GetProgress()
{
	return _iFinished/_files.size();
}

int FilmingJob::GetTotal()
{
	return _files.size();
}

int FilmingJob::GetFinished()
{
	return _iFinished;
}

vector<string> FilmingJob::GetDicomFilsToPrint()
{
	vector<string> filesToBePrinted;
	filesToBePrinted.push_back(_files[_iProgress]);
	return filesToBePrinted;
}
