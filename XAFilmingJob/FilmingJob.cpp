#include "FilmingJob.h"
#include <sstream>
#include "XAFilmingLogger.h"
#include "XAFilmingConst.h"
using namespace std;


FilmingJob::FilmingJob(int ID, vector<string> dicomFiles) : XAJob(ID), _files(dicomFiles), _iProgress(0), _iFinished(0)
{

}

void FilmingJob::Complete()
{
    if (_iProgress < GetTotal())
    {
		vector<string> filesToBePrinted = GetDicomFilsToPrint();
		Print(filesToBePrinted);

		_iFinished = _iProgress;
	    _iProgress += filesToBePrinted.size();
    }

    else 
	{
		_iFinished = GetTotal();
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

int FilmingJob::GetEstimatedTimeToFinish()
{
	auto left = GetTotal() - GetFinished();
	return left * MINUTES_PER_PRINT;
}

vector<string> FilmingJob::GetDicomFilsToPrint()
{;
	vector<string> filesToBePrinted;
	filesToBePrinted.push_back(_files[_iProgress]);
	return filesToBePrinted;
}
