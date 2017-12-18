#pragma once

#include "XAFilmingJobStatusBase.h"
#include "IXAFilmingProxy.h"
#include "IProgress.h"
#include "IPriority.h"
#include "ITimeEstimate.h"
#include "IFilmingJobMetaData.h"

class XA_FilmingInterface_Export XAFilmingJobBase : public IXAFilmingProxy, public IProgress, public IPriority, public ITimeEstimate
{
public:
    XAFilmingJobBase(XAFilmingJobStatusBase* status);
    virtual int GetJobID() = 0;
    virtual XAFilmingJobStatusBase* GetJobStatus();
	virtual IFilmingJobMetaData* GetMetaData();
    virtual void SetJobStatus(XAFilmingJobStatusBase* jobStatus);
    virtual ~XAFilmingJobBase();

    virtual void Complete();
    virtual void Continue();
    virtual void Fail();
    virtual void Pause();
    virtual void Film();
    virtual void Restart();
    virtual void Urgent();
    virtual bool CanCancel();

    //TODO: interface inheritance

	virtual int GetEstimatedTimeToFinish() {return 0;}

	virtual const std::string& GetLastResult() {return _lastResult;}
	virtual void SetLastResult(const std::string& result) {_lastResult = result;}
private:
    XAFilmingJobStatusBase* _status;
	IFilmingJobMetaData* _metaData;
	std::string _lastResult;
};
