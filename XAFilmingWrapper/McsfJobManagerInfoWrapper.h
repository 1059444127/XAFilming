#pragma once
#include "XAFilmingWrapperExportMacro.h"
#include <vector>
#include "XAFilmingJobBase.h"

namespace Mcsf {
	class ICommunicationProxy;
}


std::vector<int> XA_FilmingWrapper_Export GetJobIDsFrom(const std::string& serializedJobManagerInfo);
std::string XA_FilmingWrapper_Export SerializeFrom(const std::vector<XAFilmingJobBase*>& jobs);
void XA_FilmingWrapper_Export PushJobProgressToJobManager(const std::vector<XAFilmingJobBase*>& jobs, Mcsf::ICommunicationProxy* pProxy);