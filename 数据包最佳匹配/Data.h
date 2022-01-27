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
using ll = long long;

class Data
{
  ll origin_ip_; //十进制
  ll origin_port_;
  ll receiver_ip_; //十进制存储
  ll receiver_port_;
  ll tcp_;

public:
  friend vector<Data> ReadData(string &file_name);
  friend ostream& operator<<(ostream& os, Data& data);


  Data() = default;
  Data(ll ip1, ll port1, ll ip2, ll port2,
    ll tcp) : origin_ip_(ip1), origin_port_(port1), receiver_ip_(ip2),
    receiver_port_(port2), tcp_(tcp) {};


  ll origin_ip()const { return origin_ip_; }
  ll origin_port()const { return origin_port_; }
  ll receiver_ip()const { return receiver_ip_; }
  ll receiver_port()const { return receiver_port_; }
  ll tcp()const { return tcp_; }
};
#endif // DATA_H
ostream& operator<<(ostream& os, Data& data);
vector<Data> ReadData(string &file_name);
