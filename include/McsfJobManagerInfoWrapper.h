#pragma once
#include "XAFilmingWrapperExportMacro.h"
#include <vector>
using namespace std;

vector<int> XA_FilmingWrapper_Export GetJobIDsFrom(const string& serializedJobManagerInfo);
