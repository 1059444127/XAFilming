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
    virtual void Urgent(XAFilmingJobBase* const job);
    virtual bool IsAtomic();
    virtual std::string ToString() const = 0;
    
	//TODO: »æÖÆ×´Ì¬Í¼

    virtual XAFilmingJobStatusEnum GetStatusPriority() = 0;
};

