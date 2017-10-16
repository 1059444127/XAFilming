#pragma once
#include <IPrintStatusObserver.h>

class IPrintStatusSubject
{
public:
	virtual ~IPrintStatusSubject() 	{}
	virtual void Register(IPrintStatusObserver* pObserver) = 0;
};
