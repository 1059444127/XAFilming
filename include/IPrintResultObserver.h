#pragma once
class IPrintResultObserver
{
public:
	virtual void NofifyPrintStatus(bool bStatus) = 0;
	virtual ~IPrintResultObserver(){}
};