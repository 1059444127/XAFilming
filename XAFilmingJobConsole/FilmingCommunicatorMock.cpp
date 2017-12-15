#include "FilmingCommunicatorMock.h"
#include <iostream>
using namespace std;


void FilmingCommunicatorMock::PublishJobProgress(const std::vector<XAFilmingJobBase*>& jobs)
{
    cout << "Publish Job Progress" << endl;
    cout << "----------------------------------" << endl;
    for(auto iter = jobs.begin(); iter != jobs.end(); iter++)
    {
        auto job = *iter;
        cout << job->GetJobID() << "\t" ;
        auto jobStatus = job->GetJobStatus();
        cout << jobStatus->ToString() << "\t";
        cout << job->GetPriority() << "\t";
        cout << job->GetProgress() << endl;
    }
    cout << "----------------------------------" << endl;

}

void FilmingCommunicatorMock::Print(const std::vector<std::string>& files)
{
    files;
}

void FilmingCommunicatorMock::UpdatePrintStatus(const IFilmingJobMetaData* filmingJobMetaData)
{
}
