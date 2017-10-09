#pragma once
class INofifyPrintStatus
{
public:
	virtual void NofifyPrintStatus(bool bStatus) = 0;
	virtual ~INofifyPrintStatus(){}
};