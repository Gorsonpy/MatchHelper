#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include"Data.h"

using std::istream;
using std::ifstream;
using std::ios;
using std::reverse;
using std::string;
using std::vector;

vector<Data> ReadData(string &file_name)
{
  ifstream fin(file_name);
  vector<Data> datalist;
  uint32_t point_ip1 = 0, point_ip2 = 0,
    port1 = 0, port2 = 0, tcp = 4294967295;
  while (!fin.eof() && fin.peek() != EOF)
  {
    fin >> point_ip1 >> point_ip2 >> port1 >> port2 >> tcp;
    Data data(point_ip1, port1, point_ip2, port2, tcp);
    datalist.push_back(data);
  }
//  if (tcp == 4294967295)
    datalist.pop_back();  //ifstream可能多读最后一空行，这里特判删除一下
  fin.close();
  return datalist;
}
