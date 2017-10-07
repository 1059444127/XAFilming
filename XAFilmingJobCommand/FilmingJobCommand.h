#pragma once
#include <vector>
#include "JobCommandBase.h"

class FilmingJobCommand :
    public JobCommandBase
{
public:
    virtual void Excute(const std::string& serializedParameters);
    virtual void Excute(const std::vector<int>& IDs) = 0;
private:
    void Deserialize(const std::string& serialized_parameters, std::vector<int> jodIDs);

};

