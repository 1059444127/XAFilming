#pragma once
#include "filmingjobcommand.h"
#include "IXAFilmingJobDispatch.h"

class PauseJobCommand :
    public FilmingJobCommand
{
public:
    PauseJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

