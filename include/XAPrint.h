#pragma once

#include <vector>

#include "XAFilmingMacro.h"

#include "XAFilmingWrapperExportMacro.h"

#include <boost/function.hpp>  

namespace MCSF_NAMESPACE_FOR_XA
{
	typedef boost::function<void(const std::string&)> ResultNotifier;

	std::string XA_FilmingWrapper_Export print(const std::vector<std::string>& dicomFilePaths);

	void XA_FilmingWrapper_Export print(const std::vector<std::string>& dicomFilePaths, ResultNotifier resultNotifier);

}