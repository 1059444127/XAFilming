#pragma once
#include <vector>
#include "XAFilmingMacro.h"


void XA_FilmingCommon_Export serializeStrings(const std::vector<std::string>& stringVector, std::string& serializedString);
void XA_FilmingCommon_Export deserializeStrings(const std::string serializedString, std::vector<std::string>& splitStringVector);

std::string XA_FilmingCommon_Export serialize(const std::vector<int>& collection);
std::string XA_FilmingCommon_Export serialize(const std::vector<std::string>& collection);
int XA_FilmingCommon_Export string_to_int(const std::string& numberInStringType);
std::string XA_FilmingCommon_Export int_to_string(int number);