#pragma once
#include "filmingjobcommand.h"
#include "IXAFilmingJobDispatch.h"

class UrgentJobCommand :
    public FilmingJobCommand
{
public:
    UrgentJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::vector<int>& IDs);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

