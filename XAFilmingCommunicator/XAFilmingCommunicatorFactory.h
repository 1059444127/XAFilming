#pragma once
#include "XAFilmingCommunicatorExportMacro.h"
#include "XAFilmingMacro.h"


class XA_FilmingCommunicator_Export XAFilmingCommunicatorFactory
{
public:
    static XAFilmingCommunicatorFactory* Instance();
    ~XAFilmingCommunicatorFactory() {SAFE_DELETE_ELEMENT(_instance);}
private:
    static XAFilmingCommunicatorFactory* _instance;
    XAFilmingCommunicatorFactory();
    XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingCommunicatorFactory);
};

