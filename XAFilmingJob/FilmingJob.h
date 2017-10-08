#pragma once
#include "XAJob.h"
#include <vector>
#include <queue>
#include "XAFilmingMacro.h"

using namespace std;
class FilmingJob :
    public XAJob
{
public:
    FilmingJob(int ID, vector<string> dicomFiles);
    virtual void Complete();
    virtual string GetProgress();
private:
    vector<string> _files;
    queue<string> _fileQueue;
    int _iProgress;
};

