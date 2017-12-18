#pragma once
class IPrintResultObserver
{
public:
	virtual void NotifyPrintResult(std::string result) = 0;
	virtual ~IPrintResultObserver(){}
};