#include "FilmingJobCommand.h"
#include "McsfJobManagerInfoWrapper.h"


void FilmingJobCommand::Excute(const string& serializedParameters)
{
	auto jobIDs = Deserialize(serializedParameters);
    Excute(jobIDs);
}

vector<int> FilmingJobCommand::Deserialize(const string& serialized_parameters)
{
	return GetJobIDsFrom(serialized_parameters);
}
