#pragma once
#ifndef DATA_H

#include<iostream>
#include<fstream>
#include<string>
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
  friend ifstream& Read(string &file_name, Data &data);
  friend ostream& print(ostream& os, Data& data);
};
#endif // DATA_H

ifstream& Read(string &file_name, Data &data);
uint32_t TransIp(string s);
ostream& print(ostream& os, Data& data);
