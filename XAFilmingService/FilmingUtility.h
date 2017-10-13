#pragma once

#include <vector>

MCSF_FILMING_BEGIN_NAMESPACE

	void Print(const std::vector<std::string>& dicomFilePaths);

	const std::string TEMP_DIRECTORY = "E:\\Images\\Temp\\";

	std::string CreateDicomFileName();

MCSF_FILMING_END_NAMESPACE