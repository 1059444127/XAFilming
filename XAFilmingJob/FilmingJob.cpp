#include "FilmingJob.h"
#include <sstream>
#include "XAFilmingLogger.h"


FilmingJob::FilmingJob(int ID, vector<string> dicomFiles) : XAJob(ID), _files(dicomFiles), _iProgress(0)
{

}

void FilmingJob::Complete()
{
    _iProgress < _files.size() 
	? _iProgress++ 
	: XAJob::Complete();
}

string FilmingJob::GetProgress()
{
    stringstream ss;
    ss << _iProgress << "/" << _files.size();
    return ss.str();
}
