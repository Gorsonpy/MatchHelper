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
  uint32_t tcp_;
public:
  friend vector<Rule> ReadRule(string& file_name);
  friend ostream& operator<<(ostream& out, Rule rule);


  Rule() = default;
  Rule(uint32_t ip1, uint32_t ip2, uint32_t port1_beg, uint32_t port1_end,
       uint32_t port2_beg, uint32_t port2_end, uint32_t tcp) 
       : origin_ip_(ip1), receiver_ip_(ip2), origin_port_beg_(port1_beg),
        origin_port_end_(port1_end), receiver_port_beg_(port2_beg), 
        receiver_port_end_(port2_end), tcp_(tcp) {}


  uint32_t origin_ip()const { return origin_ip_; }
  uint32_t receiver_ip()const{ return receiver_ip_; }
  uint32_t origin_port_beg()const { return origin_port_beg_; }
  uint32_t origin_port_end()const { return origin_port_end_; }
  uint32_t receiver_port_beg()const { return receiver_port_beg_; }
  uint32_t receiver_port_end()const { return receiver_port_end_; }
  uint32_t tcp()const { return tcp_; }
};
#endif // !RULE_H
uint32_t TransIp(string s);
vector<Rule> ReadRule(string& file_name);
