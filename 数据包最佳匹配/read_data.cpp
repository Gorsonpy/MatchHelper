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
  uint32_t point_ip1 = 4294967295, point_ip2 = 0,
    port1 = 0, port2 = 0, tcp = 0;
  while (!fin.eof() && fin.peek() != EOF)
  {
    Data data;
    fin >> point_ip1 >> point_ip2 >> port1 >> port2 >> tcp;
    data.origin_ip_ = point_ip1;
    data.receiver_ip_ = point_ip2;
    data.origin_port_ = port1;
    data.receiver_port_ = port2;
    data.tcp_ = tcp;
    datalist.push_back(data);
  }
  if (point_ip1 == 4294967295)
    datalist.pop_back();  //fstream可能多读最后一空行，这里特判删除一下。
  fin.close();
  return datalist;
}
ostream& operator<<(ostream& os, Data& data)
{
  os << data.origin_ip_ << " " << data.receiver_ip_ << " "
    << data.origin_port_ << " " << data.receiver_port_ << " "
    << data.tcp_;
  return os;
}