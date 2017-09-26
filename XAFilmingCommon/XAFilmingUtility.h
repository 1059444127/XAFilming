#pragma once
#include <vector>
using namespace  std;

void split(const string serializedString, const string separator, vector<string> & splitStringVector);
void join(const vector<string> stringVector, const string separator, string &joinedString);
