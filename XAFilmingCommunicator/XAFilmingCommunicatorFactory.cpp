#include "XAFilmingCommunicatorFactory.h"
#include "FilmingCommunicator.h"

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::_instance = new XAFilmingCommunicatorFactory();

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::Instance()
{
    return _instance;
}

IXAFilmingCommunicationProxy* XAFilmingCommunicatorFactory::CreateCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
    return new FilmingCommunicator(pProxy);
}

XAFilmingCommunicatorFactory::XAFilmingCommunicatorFactory()
{
}


