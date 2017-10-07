#pragma once
#include "filmingjobcommand.h"
#include "IXAFilmingJobDispatch.h"

class ContinueJobCommand :
    public FilmingJobCommand
{
public:
    ContinueJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

