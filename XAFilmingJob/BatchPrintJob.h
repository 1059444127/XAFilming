#pragma once
#include "XAJob.h"
#include <vector>
#include <queue>

class BatchPrintJob :
    public XAJob
{
public:
    BatchPrintJob(int ID, std::vector<std::string> dicomFiles);
    virtual void Complete();
    virtual double GetProgress();

	virtual int GetTotal();
	virtual int GetFinished();
	virtual int GetEstimatedTimeToFinish();
private:
    std::vector<std::string> _files;
    std::queue<std::string> _fileQueue;
    int _iProgress;
	int _iFinished;
	std::vector<std::string> GetDicomFilsToPrint();
};

