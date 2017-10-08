#pragma once
#include <vector>
#include <XAFilmingJobBase.h>

class IXAFilmingCommunicator
{
    virtual void PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs) = 0;
    virtual void Print(const std::vector<std::string>& files) = 0;
};
