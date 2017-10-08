#include "XAFilmingCommunicatorFactory.h"
#include "FilmingCommunicator.h"

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::_instance = new XAFilmingCommunicatorFactory();

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::Instance()
{
    return _instance;
}

IXAFilmingCommunicator* XAFilmingCommunicatorFactory::CreateCommunicator()
{
    return new FilmingCommunicator();
}

XAFilmingCommunicatorFactory::XAFilmingCommunicatorFactory()
{
}


