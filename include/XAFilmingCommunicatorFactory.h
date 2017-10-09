#pragma once
#include "XAFilmingCommunicatorExportMacro.h"
#include "XAFilmingMacro.h"
#include "IXAFilmingCommunicator.h"


class XA_FilmingCommunicator_Export XAFilmingCommunicatorFactory
{
public:
    static XAFilmingCommunicatorFactory* Instance();
    IXAFilmingCommunicator* CreateCommunicator();
    ~XAFilmingCommunicatorFactory() {SAFE_DELETE_ELEMENT(_instance);}
private:
    static XAFilmingCommunicatorFactory* _instance;
    XAFilmingCommunicatorFactory();
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingCommunicatorFactory);
};

