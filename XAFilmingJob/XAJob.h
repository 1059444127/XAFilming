#pragma once
#include "XAFilmingJobBase.h"
#include "XAFilmingMacro.h"

class XAJob :
    public XAFilmingJobBase
{
public:
    XAJob(int ID);
    virtual int GetJobID();
    virtual void ResetPriority();
    virtual int GetPriority();
    virtual void TopPriority();
    virtual double GetProgress();
	virtual int GetTotal();
	virtual int GetFinished();
private:
    static int MaxPriority;
    int _iID;
    int _iPriority;
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAJob);
};

