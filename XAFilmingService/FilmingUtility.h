#pragma once

using namespace std;

#include <vector>

MCSF_FILMING_BEGIN_NAMESPACE

	void Print(const vector<string>& dicomFilePaths);

	const string TEMP_DIRECTORY = "E:\\Images\\Temp\\";

	string CreateDicomFileName();

MCSF_FILMING_END_NAMESPACE