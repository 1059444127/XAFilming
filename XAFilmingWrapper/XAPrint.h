#pragma once

#include <vector>

#include "XAFilmingMacro.h"

using namespace std;

namespace MCSF_NAMESPACE_FOR_XA
{

	bool Print(const vector<string>& dicomFilePaths);

	const string TEMP_DIRECTORY = "E:\\Images\\Temp\\";

	string CreateDicomFileName();

}