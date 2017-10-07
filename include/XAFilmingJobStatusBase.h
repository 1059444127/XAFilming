#pragma once
#include <string>
#include "XAFilmingInterfaceExportMacro.h"
#include "XAFilmingJobStatusEnum.h"

class XAFilmingJobBase;

class XA_FilmingInterface_Export XAFilmingJobStatusBase
{
public:
    virtual void Continue(XAFilmingJobBase*  const job);
    virtual void Pause(XAFilmingJobBase*  const job);
    virtual void Restart(XAFilmingJobBase*  const job); 
    virtual void Print(XAFilmingJobBase* const job);
    virtual void Complete(XAFilmingJobBase* const job);
    virtual void Fail(XAFilmingJobBase* const job);
    virtual std::string ToString() const = 0;
    
    virtual XAFilmingJobStatusEnum GetStatusPriority() = 0;
};

