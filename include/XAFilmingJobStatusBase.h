#pragma once
#include <string>
#include "XAFilmingInterfaceExportMacro.h"

class IXAFilmingJob;

class XA_FilmingInterface_Export XAFilmingJobStatusBase
{
public:
    virtual bool Continue(IXAFilmingJob*  const job);
    virtual bool Pause(IXAFilmingJob*  const job);
    virtual bool Restart(IXAFilmingJob*  const job); 
    virtual std::string ToString() const = 0;
};

