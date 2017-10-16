#pragma once
class IPrintStatusObserver
{
public:
	virtual void NofifyPrintStatus(bool bStatus) = 0;
	virtual ~IPrintStatusObserver(){}
};