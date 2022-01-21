#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include"Data.h"
using std::istream;
using std::ifstream;
using std::ios;
using std::reverse;
using std::string;

uint32_t int_pow(int c, int e)
{
  uint32_t base = c, ans = 1;
  while (e > 0)
  {
    if (e & 1)
      ans *= base;
    base *= base;
    e >>= 1;
  }
  return ans;
}



uint32_t TransIp(string s)
{
  auto it = s.begin();
  while (it != s.end())
    it = *it == '.' ? s.erase(it) : it + 1;
  reverse(s.begin(), s.end());
  uint32_t base = 1, ans = 0;
  for (auto c : s)
  {
    ans += (c - 48) * base;
    base *= int_pow(2, 8);
  }
  return ans;
}
ifstream& Read(string &name, Data &data)
{
  ifstream fin(name);
  uint32_t point_ip1 = 0, point_ip2 = 0, port1 = 0, port2 = 0, tcp = 0;
  fin >> point_ip1 >> point_ip2 >> port1 >> port2 >> tcp;
  data.origin_ip_ = point_ip1;
  data.receiver_ip_ = point_ip2;
  data.origin_port_ = port1;
  data.receiver_port_ = port2;
  data.tcp_ = tcp;
  fin.close();
  return fin;
}
ostream& print(ostream& os, Data& data)
{
  os << data.origin_ip_ << " " << data.receiver_ip_ << " "
    << data.origin_port_ << " " << data.receiver_port_ << " "
    << data.tcp_;
  return os;
}