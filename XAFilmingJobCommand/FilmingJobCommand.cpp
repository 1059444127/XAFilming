#include "FilmingJobCommand.h"
#include "McsfJobManagerInfoWrapper.h"


void FilmingJobCommand::Excute(const std::string& serializedParameters)
{
	auto jobIDs = Deserialize(serializedParameters);
    Excute(jobIDs);
}

std::vector<int> FilmingJobCommand::Deserialize(const std::string& serialized_parameters)
{
	return GetJobIDsFrom(serialized_parameters);
}
