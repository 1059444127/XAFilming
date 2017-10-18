#pragma once
#include <XAFilmingJobBase.h>

class JobMock :
    public XAFilmingJobBase
{
public:
    JobMock(XAFilmingJobStatusBase* status, int _i_id, int i_priority)
        : XAFilmingJobBase(status),
          _iID(_i_id),
          _iPriority(i_priority)
    {
    }

    virtual int GetJobID() {return _iID;};
    virtual void TopPriority() {}
    virtual int GetPriority() { return _iPriority;}
    virtual void ResetPriority() {};
    virtual double GetProgress() {return 0;}
	virtual int GetTotal() {return 0;}
	virtual int GetFinished() {return 0;}
private:
    int _iID;
    int _iPriority;
};

