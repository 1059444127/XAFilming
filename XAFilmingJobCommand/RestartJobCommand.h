#pragma once
#include "filmingjobcommand.h"

class RestartJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

