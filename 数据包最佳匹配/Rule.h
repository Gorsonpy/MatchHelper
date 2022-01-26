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
using ll = long long;

class Rule
{
  ll origin_ip_beg_;
  ll origin_ip_end_;
  ll receiver_ip_beg_;
  ll receiver_ip_end_;
  ll origin_port_beg_;
  ll origin_port_end_;
  ll receiver_port_beg_;
  ll receiver_port_end_;
  ll tcp_;
public:
  friend vector<Rule> ReadRule(string& file_name);
  friend ostream& operator<<(ostream& out, Rule rule);


  Rule() = default;
  Rule(ll ip1_beg, ll ip1_end, ll ip2_beg, ll ip2_end,
    ll port1_beg, ll port1_end,
       ll port2_beg, ll port2_end, ll tcp) 
       : origin_ip_beg_(ip1_beg), origin_ip_end_(ip1_end), receiver_ip_beg_(ip2_beg), 
        receiver_ip_end_(ip2_end), origin_port_beg_(port1_beg),
        origin_port_end_(port1_end), receiver_port_beg_(port2_beg), 
        receiver_port_end_(port2_end), tcp_(tcp) {}


  ll origin_ip_beg()const { return origin_ip_beg_; }
  ll origin_ip_end()const { return origin_ip_end_; }
  ll receiver_ip_beg()const { return receiver_ip_beg_; }
  ll receiver_ip_end()const{ return receiver_ip_end_; }
  ll origin_port_beg()const { return origin_port_beg_; }
  ll origin_port_end()const { return origin_port_end_; }
  ll receiver_port_beg()const { return receiver_port_beg_; }
  ll receiver_port_end()const { return receiver_port_end_; }
  ll tcp()const { return tcp_; }
};
#endif // !RULE_H

vector<Rule> ReadRule(string& file_name);
