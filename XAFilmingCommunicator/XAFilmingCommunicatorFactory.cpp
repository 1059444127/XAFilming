#include "XAFilmingCommunicatorFactory.h"
#include "FilmingCommunicator.h"
#include "PrintCallBackHandler.h"

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::_instance = new XAFilmingCommunicatorFactory();

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::Instance()
{
    return _instance;
}

IXAFilmingCommunicationProxy* XAFilmingCommunicatorFactory::CreateCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
	auto pCallBackCommandHandler = new PrintCallBackHandler();
    return new FilmingCommunicator(pProxy, pCallBackCommandHandler);
}

XAFilmingCommunicatorFactory::XAFilmingCommunicatorFactory()
{
}


