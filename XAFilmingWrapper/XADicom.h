#pragma once
#include <vector>
#include "XAFilmingWrapperExportMacro.h"

class DicomDataHeaderPacketHeader;
bool XA_FilmingWrapper_Export SaveStringToDicomFile(const std::string& serializedDataheader, std::string& filePaths, DicomDataHeaderPacketHeader& dicomDataHeaderPacketHeader);
