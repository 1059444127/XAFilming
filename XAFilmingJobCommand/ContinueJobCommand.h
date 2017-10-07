#pragma once
#include "filmingjobcommand.h"

class ContinueJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

