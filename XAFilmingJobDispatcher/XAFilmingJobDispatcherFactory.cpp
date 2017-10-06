#include "XAFilmingJobDispatcherFactory.h"

XAFilmingJobDispatcherFactory* XAFilmingJobDispatcherFactory::_instance = new XAFilmingJobDispatcherFactory();

XAFilmingJobDispatcherFactory* XAFilmingJobDispatcherFactory::Instance()
{
    return _instance;
}

