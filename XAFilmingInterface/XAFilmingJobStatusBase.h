#pragma once
#include <string>
#include "XAFilmingInterfaceExportMacro.h"

class IXAFilmingJob;

class XA_FilmingInterface_Export XAFilmingJobStatusBase
{
public:
    virtual void Continue(IXAFilmingJob*  const job);
    virtual void Pause(IXAFilmingJob*  const job);
    virtual void Restart(IXAFilmingJob*  const job); 
    virtual std::string ToString() const = 0;
};

