#pragma once
#ifndef RULE_H

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
using std::string;

class Rule
{
  uint32_t origin_ip_;
  uint32_t receiver_ip_;
  uint32_t origin_port_beg_;
  uint32_t origin_port_end_;
  uint32_t receiver_port_beg_;
  uint32_t receiver_port_end_;
  uint32_t tcp_beg_;
  uint32_t tcp_end_;
public:
  friend vector<Rule> ReadRule(string& file_name);
};
#endif // !RULE_H
uint32_t TransIp(string s);
vector<Rule> ReadRule(string& file_name);
