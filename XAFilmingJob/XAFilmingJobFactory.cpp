#include "XAFilmingJobFactory.h"

XAFilmingJobFactory* XAFilmingJobFactory::_instance = new XAFilmingJobFactory();

XAFilmingJobFactory* XAFilmingJobFactory::Instance()
{
    return _instance;
}
