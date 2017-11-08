#pragma once
#include <vector>
#include "XAFilmingWrapperExportMacro.h"

bool XA_FilmingWrapper_Export SaveStringToDicomFile(const std::string& serializedDataheader, std::string& filePaths, std::string& serializedPacketHeader = std::string());
