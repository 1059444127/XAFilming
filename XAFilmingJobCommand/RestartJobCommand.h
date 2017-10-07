#pragma once
#include "filmingjobcommand.h"
#include "IXAFilmingJobDispatch.h"

class RestartJobCommand :
    public FilmingJobCommand
{
public:
    RestartJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

