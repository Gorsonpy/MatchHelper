#pragma once
#ifndef DATA_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istream;
using std::ostream;
class Data
{
  uint32_t origin_ip_; //ʮ����
  uint32_t origin_port_;
  uint32_t receiver_ip_; //ʮ���ƴ洢
  uint32_t receiver_port_;
  uint32_t tcp_;

public:
  friend vector<Data> Read(string &file_name);
  friend ostream& operator<<(ostream& os, Data& data);
};
#endif // DATA_H
ostream& operator<<(ostream& os, Data& data);
vector<Data> Read(string &file_name);
uint32_t TransIp(string s);
