#pragma once
#include "IXAFilmingJobDispatch.h"
#include "FilmingJobCommand.h"

class DeleteJobCommand :
    public FilmingJobCommand
{
public:
    DeleteJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

