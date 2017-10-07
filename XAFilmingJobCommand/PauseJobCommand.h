#pragma once
#include "filmingjobcommand.h"

class PauseJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

