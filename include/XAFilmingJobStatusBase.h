#pragma once
#include <string>

class IXAFilmingJob;

class XAFilmingJobStatusBase
{
    virtual void Continue(IXAFilmingJob*  const job);
    virtual void Pause(IXAFilmingJob*  const job);
    virtual void Restart(IXAFilmingJob*  const job); 
    virtual std::string ToString() const = 0;
};

