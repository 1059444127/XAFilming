#pragma once
#include "XAFilmingJobCommandBase.h"

class RefreshJobCommand :
    public XAFilmingJobCommandBase
{
public:
    virtual void Excute(const std::string& serializedParameters);
};

