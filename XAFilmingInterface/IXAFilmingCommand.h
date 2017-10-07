#pragma once
#include <string>

class IXAFilmingCommand
{
public:
    virtual void Excute(const std::string & serializedParameters) = 0;
};
