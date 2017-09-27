#pragma once
#include <vector>
using namespace  std;

void serializeStrings(const vector<string>& stringVector, string& serializedString);
void deserializeStrings(const string serializedString, vector<string>& splitStringVector);

