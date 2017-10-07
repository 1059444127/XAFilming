#pragma once
#include "FilmingJobCommand.h"

class DeleteJobCommand :
    public FilmingJobCommand
{
public:
    virtual void Excute(const std::vector<int>& IDs);
};

