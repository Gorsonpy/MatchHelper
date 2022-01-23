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
  uint32_t origin_ip_; //十进制
  uint32_t origin_port_;
  uint32_t receiver_ip_; //十进制存储
  uint32_t receiver_port_;
  uint32_t tcp_;

public:
  friend vector<Data> ReadData(string &file_name);
  friend ostream& operator<<(ostream& os, Data& data);
  Data() = default;
  Data(uint32_t ip1, uint32_t port1, uint32_t ip2, uint32_t port2,
    uint32_t tcp) : origin_ip_(ip1), origin_port_(port1), receiver_ip_(ip2),
    receiver_port_(port2), tcp_(tcp) {};
};
#endif // DATA_H
ostream& operator<<(ostream& os, Data& data);
vector<Data> ReadData(string &file_name);
