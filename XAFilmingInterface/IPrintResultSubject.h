#pragma once
#include "IPrintResultObserver.h"

class IPrintResultSubject
{
public:
	virtual ~IPrintResultSubject() 	{}
	virtual void Register(IPrintResultObserver* pObserver) = 0;
};
