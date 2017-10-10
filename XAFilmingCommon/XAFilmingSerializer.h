#pragma once
#include <vector>
#include "XAFilmingMacro.h"

using namespace  std;
	
void XA_FilmingCommon_Export serializeStrings(const vector<string>& stringVector, string& serializedString);
void XA_FilmingCommon_Export deserializeStrings(const string serializedString, vector<string>& splitStringVector);

string XA_FilmingCommon_Export serialize(const vector<int>& collection);
string XA_FilmingCommon_Export serialize(const vector<string>& collection);
int XA_FilmingCommon_Export string_to_int(const string& numberInStringType);