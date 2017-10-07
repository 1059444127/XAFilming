#pragma once
#include "filmingjobcommand.h"
#include "IXAFilmingJobDispatch.h"

class StopJobCommand :
    public FilmingJobCommand
{
public:
    StopJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

