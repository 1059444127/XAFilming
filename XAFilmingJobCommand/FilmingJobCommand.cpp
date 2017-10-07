#include "FilmingJobCommand.h"


void FilmingJobCommand::Excute(const std::string& serializedParameters)
{
    std::vector<int> jobIDs;
    Deserialize(serializedParameters, jobIDs);
    Excute(jobIDs);
}

void FilmingJobCommand::Deserialize(const std::string& serialized_parameters, std::vector<int> jodIDs)
{
    //TODO: deserialize jobInfo to get jobIDs;
}
