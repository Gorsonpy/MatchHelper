#pragma once
#ifndef MATCH_UTIL_H
#include<vector>
#include "Data.h"
#include "Rule.h"

using std::vector;

vector<int32_t> DoMatch(vector<Data> &datalist, vector<Rule> &rulelist);
bool check(Data& data, Rule& rule);
void WriteInFile(string &file_name, vector<Data> &datalist,
  vector<Rule> &rulelist);
#endif // !MATCH_UTIL_H
