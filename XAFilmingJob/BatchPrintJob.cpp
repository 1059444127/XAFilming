#include "BatchPrintJob.h"
#include <sstream>
#include "XAFilmingLogger.h"
#include "XAFilmingConst.h"
using namespace std;


BatchPrintJob::BatchPrintJob(int ID, vector<string> dicomFiles) : XAJob(ID), _files(dicomFiles), _iProgress(0), _iFinished(0)
{

}

void BatchPrintJob::Complete()
{
    if (_iProgress < GetTotal())
    {
		vector<string> filesToBePrinted = GetDicomFilsToPrint();
		Print(filesToBePrinted);

		_iFinished = _iProgress;
	    _iProgress += filesToBePrinted.size();
    }

    else 
	{
		_iFinished = GetTotal();

		UpdatePrintStatus(GetMetaData());

		XAJob::Complete();
	}

}

double BatchPrintJob::GetProgress()
{
	return _iFinished/_files.size();
}

int BatchPrintJob::GetTotal()
{
	return _files.size();
}

int BatchPrintJob::GetFinished()
{
	return _iFinished;
}

int BatchPrintJob::GetEstimatedTimeToFinish()
{
	auto left = GetTotal() - GetFinished();
	return left * MINUTES_PER_PRINT;
}

vector<string> BatchPrintJob::GetDicomFilsToPrint()
{;
	vector<string> filesToBePrinted;
	filesToBePrinted.push_back(_files[_iProgress]);
	return filesToBePrinted;
}
