#pragma once
class IProgress
{
public:
    virtual double GetProgress() = 0;
	virtual int GetTotal() = 0;
	virtual int GetFinished() = 0;
	virtual const std::string& GetLastResult() = 0;
	virtual void SetLastResult(const std::string& result) = 0;
};