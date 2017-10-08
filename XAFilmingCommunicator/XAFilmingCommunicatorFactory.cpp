#include "XAFilmingCommunicatorFactory.h"

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::_instance = new XAFilmingCommunicatorFactory();

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::Instance()
{
    return _instance;
}

XAFilmingCommunicatorFactory::XAFilmingCommunicatorFactory()
{
}


