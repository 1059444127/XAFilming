#pragma once
#include <vector>
#include "XAFilmingMacro.h"

using namespace  std;
	
XA_FilmingCommon_Export void serializeStrings(const vector<string>& stringVector, string& serializedString);
XA_FilmingCommon_Export void deserializeStrings(const string serializedString, vector<string>& splitStringVector);

template<class T>
XA_FilmingCommon_Export string serialize(const vector<T>& collection);