#pragma once

#include "XAFilmingWrapperExportMacro.h"
#include <vector>
#include <XAFilmingMacro.h>
#include <McsfNetBase/mcsf_netbase_icommunication_proxy.h>

void XA_FilmingWrapper_Export SendPrintCommand(const std::vector<std::string>& files, MCSF_NAMESPACE_FOR_XA::ICommunicationProxy* pProxy);
