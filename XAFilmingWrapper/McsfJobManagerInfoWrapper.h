#pragma once
#include "XAFilmingWrapperExportMacro.h"
#include <vector>
#include "XAFilmingJobBase.h"

namespace Mcsf {
	class ICommunicationProxy;
}

using namespace std;

vector<int> XA_FilmingWrapper_Export GetJobIDsFrom(const string& serializedJobManagerInfo);
string XA_FilmingWrapper_Export SerializeFrom(const vector<XAFilmingJobBase*>& jobs);
void XA_FilmingWrapper_Export PushJobProgressToJobManager(const vector<XAFilmingJobBase*>& jobs, Mcsf::ICommunicationProxy* pProxy);