#pragma once
#include "IXAFilmingCommand.h"
#include "IXAFilmingJobDispatch.h"

class RefreshJobCommand :
    public IXAFilmingCommand
{
public:
    RefreshJobCommand(IXAFilmingJobDispatch* jobDispatcher);
    virtual void Excute(const std::string& serializedParameters);
private:
    IXAFilmingJobDispatch* _jobDispatcher;
};

