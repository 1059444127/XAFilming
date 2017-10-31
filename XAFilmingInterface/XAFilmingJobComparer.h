#pragma once
#include "XAFilmingJobBase.h"

class XA_FilmingInterface_Export XAFilmingJobComparer
{
public:
    bool operator()(XAFilmingJobBase* left, XAFilmingJobBase* right);
};

