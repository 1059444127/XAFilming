#pragma once
#include <vector>
#include "XAFilmingMacro.h"

using namespace  std;
	
XA_FilmingCommon_Export void serializeStrings(const vector<string>& stringVector, string& serializedString);
XA_FilmingCommon_Export void deserializeStrings(const string serializedString, vector<string>& splitStringVector);
