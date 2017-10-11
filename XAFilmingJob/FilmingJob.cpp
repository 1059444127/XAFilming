#include "FilmingJob.h"
#include <sstream>
#include "XAFilmingLogger.h"


FilmingJob::FilmingJob(int ID, vector<string> dicomFiles) : XAJob(ID), _files(dicomFiles), _iProgress(0)
{

}

void FilmingJob::Complete()
{
    if (_iProgress < _files.size())
    {
		vector<string> filesToBePrinted = GetDicomFilsToPrint();
		Print(filesToBePrinted);
	    _iProgress++;
    }

    else XAJob::Complete();

}

string FilmingJob::GetProgress()
{
    stringstream ss;
    ss << _iProgress << "/" << _files.size();
    return ss.str();
}

vector<string> FilmingJob::GetDicomFilsToPrint()
{
	vector<string> filesToBePrinted;
	filesToBePrinted.push_back(_files[_iProgress]);
	return filesToBePrinted;
}
