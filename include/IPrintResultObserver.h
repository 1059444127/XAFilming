#pragma once
class IPrintResultObserver
{
public:
	virtual void NotifyPrintResult(bool bStatus) = 0;
	virtual ~IPrintResultObserver(){}
};