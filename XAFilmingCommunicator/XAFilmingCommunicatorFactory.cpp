#include "XAFilmingCommunicatorFactory.h"
#include "FilmingCommunicator.h"
#include "PrintCallbackHandler.h"

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::_instance = new XAFilmingCommunicatorFactory();

XAFilmingCommunicatorFactory* XAFilmingCommunicatorFactory::Instance()
{
    return _instance;
}

IXAFilmingCommunicationProxy* XAFilmingCommunicatorFactory::CreateCommunicator(MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy)
{
	auto pCallBackCommandHandler = new PrintCallbackHandler();
    return new FilmingCommunicator(pProxy, pCallBackCommandHandler);
}

XAFilmingCommunicatorFactory::XAFilmingCommunicatorFactory()
{
}


