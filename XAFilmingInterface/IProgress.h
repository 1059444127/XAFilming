#pragma once
class IProgress
{
public:
    virtual double GetProgress() = 0;
	virtual int GetTotal() = 0;
	virtual int GetFinished() = 0;
};