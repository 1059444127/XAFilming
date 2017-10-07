#pragma once
#include "filmingjobcommand.h"

class UrgentJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

