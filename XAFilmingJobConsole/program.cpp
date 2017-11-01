#include <iostream>
#include "IXAFilmingJobDispatch.h"
#include <sstream>
#include <map>
#include "XAFilmingJobDispatcherFactory.h"
#include "FilmingCommunicatorMock.h"
#include "XAFilmingJobFactory.h"
using namespace std;

IXAFilmingJobDispatch* job_dispatcher;

void addJob(const vector<int> IDs)
{
    vector<string> files; files.push_back("1"); //files.push_back("2"); files.push_back("3");
    auto job = XAFilmingJobFactory::Instance()->CreateFilmingJob(files);
    job_dispatcher->AddJob(job);
}

void continueJobs(const vector<int> IDs)
{
    job_dispatcher->ContinueJobs(IDs);
}

void deleteJobs(const vector<int> IDs)
{
    job_dispatcher->DeleteJobs(IDs);
}

void pauseJobs(const vector<int> IDs)
{
    job_dispatcher->PauseJobs(IDs);
}

void showStatus(const vector<int> IDs)
{
    job_dispatcher->PushJobsProgress();
}

void restartJobs(const vector<int> IDs)
{
    job_dispatcher->RestartJobs(IDs);
}

void urgentJobs(const vector<int> IDs)
{
    job_dispatcher->UrgentJobs(IDs);
}

void printed(const vector<int> IDs)
{
    job_dispatcher->NotifyPrintResult(true);
}

void failed(const vector<int> IDs)
{
	job_dispatcher->NotifyPrintResult(false);
}


typedef void (*Execute)(const vector<int> parameters);
map<string, Execute> command_map;


void printUsage()
{
    cout << "Operation List" << endl;
    cout << "\t" << "addJob" << endl;
    cout << "\t" << "continueJobs 1 2 3" << endl;
    cout << "\t" << "deleteJobs 1 2 3" << endl;
    cout << "\t" << "pauseJobs 1 2 3" << endl;
    cout << "\t" << "status" << endl;
    cout << "\t" << "restartJobs 1 2 3" <<endl;
    cout << "\t" << "urgentJobs 1 2 3" << endl;
    cout << "\t" << "printed" << endl;
	cout << "\t" << "failed" << endl;
}


vector<int> splitParameters(stringstream& ss)
{
    vector<int> parameters;
    while(!ss.eof())
    {
        int i;
        ss >> i;
        parameters.push_back(i);
    }
    return parameters;
}

void ExcuteCommand(string str)
{
    stringstream ss;
    ss << str;
    string commandName;
    ss >> commandName;

    vector<int> parameters = splitParameters(ss);

    if(command_map.find(commandName) != command_map.end())
    {
        auto command = command_map[commandName];
        command(parameters);
    }
}

void LauguageTest()
{
    char* s = "addJob 1 2 3";
    stringstream ss;
    string commandName;
    ss << s;
    ss >> commandName;
    cout << commandName << endl;

    cout << ss.str() << endl;

    cout << "string(\"123\") == \"123\""  << endl;
    cout << (string("123") == "123") << endl;


    cout << "input a character to continue" << endl;
    char c;
    cin >> c;
}

void main()
{
    command_map["addJob"] = addJob;
    command_map["continueJobs"] = continueJobs;
    command_map["deleteJobs"] = deleteJobs;
    command_map["pauseJobs"] = pauseJobs;
    command_map["status"] = showStatus;
    command_map["restartJobs"] = restartJobs;
    command_map["urgentJobs"] = urgentJobs;
    command_map["printed"] = printed;
	command_map["failed"] = failed;

    job_dispatcher = XAFilmingJobDispatcherFactory::Instance()->CreateJobDispatcher(new FilmingCommunicatorMock());

    while(true)
    {
        printUsage();
        char command[100];
        cin.getline(command, 100);
        ExcuteCommand(command);
    }
}
