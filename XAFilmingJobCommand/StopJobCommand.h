#pragma once
#include "filmingjobcommand.h"

class StopJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

