#pragma once
#include <vector>
#include "XAFilmingJobCommandBase.h"

class FilmingJobCommand :
    public XAFilmingJobCommandBase
{
public:
    virtual void Excute(const std::string& serializedParameters);
    virtual void Excute(const std::vector<int>& IDs) = 0;
private:
    std::vector<int> Deserialize(const std::string& serialized_parameters);

};

