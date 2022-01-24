#include<iostream>
#include<vector>
#include<fstream>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"

using std::ofstream;
using std::endl;

void WriteInFile(string &file_name, vector<Data> &datalist,
  vector<Rule> &rulelist)
{
  ofstream fout(file_name);
  auto ans = DoMatch(datalist, rulelist);
  for (auto i : ans)
  {
    fout << i << endl;
  }
  fout.close();
}

