#pragma once
#include "JobCommandBase.h"

class RefreshJobCommand :
    public JobCommandBase
{
public:
    virtual void Excute(const std::string& serializedParameters);
};

