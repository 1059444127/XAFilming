#include "XAFilmingJobDispatcherFactory.h"
#include "FilmingJobDispatcher.h"

XAFilmingJobDispatcherFactory* XAFilmingJobDispatcherFactory::_instance = new XAFilmingJobDispatcherFactory();

XAFilmingJobDispatcherFactory* XAFilmingJobDispatcherFactory::Instance()
{
    return _instance;
}

IXAFilmingJobDispatch* XAFilmingJobDispatcherFactory::CreateJobDispatcher(IXAFilmingCommunicationProxy* communicator)
{
    return new FilmingJobDispatcher(communicator);
}

