#pragma once

#include <vector>

#include "XAFilmingMacro.h"

#include "XAFilmingWrapperExportMacro.h"

namespace MCSF_NAMESPACE_FOR_XA
{

	bool XA_FilmingWrapper_Export print(const std::vector<std::string>& dicomFilePaths);

}