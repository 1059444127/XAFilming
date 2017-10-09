#pragma once
#include "IXAFilmingCommand.h"
#include "IXAFilmingJobDispatch.h"
class XAFilmingJobCommandBase :
    public IXAFilmingCommand
{
public:
    XAFilmingJobCommandBase() : _jobDispatcher(nullptr) {  }
    virtual void SetJobDispatcher(IXAFilmingJobDispatch* jobDispatcher) {_jobDispatcher = jobDispatcher;}
protected:
    IXAFilmingJobDispatch* _jobDispatcher;
};

