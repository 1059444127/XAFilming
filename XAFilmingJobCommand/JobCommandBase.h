#pragma once
#include "IXAFilmingCommand.h"
#include "IXAFilmingJobDispatch.h"
class JobCommandBase :
    public IXAFilmingCommand
{
public:
    JobCommandBase() : _jobDispatcher(nullptr) {  }
    virtual void SetJobDispatcher(IXAFilmingJobDispatch* jobDispatcher) {_jobDispatcher = jobDispatcher;}
protected:
    IXAFilmingJobDispatch* _jobDispatcher;
};

