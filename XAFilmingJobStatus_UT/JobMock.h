#pragma once
#include "XAFilmingJobBase.h"

class JobMock :
    public XAFilmingJobBase
{
public:
    virtual void TopPriority() {}
    virtual int GetPriority() {return 0;}
    virtual void ResetPriority() {}
    virtual double GetProgress() {return 0;}
	virtual int GetTotal() {return 0;}
	virtual int GetFinished() {return 0;}
    JobMock();

    virtual int GetJobID();
};

