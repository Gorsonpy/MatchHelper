#include<iostream>
#include"Rule.h"

using std::ostream;


ostream& operator<<(ostream& out, Rule rule)
{
  out << rule.origin_ip_ << " " << rule.receiver_ip_ << " "
    << rule.origin_port_beg_ << " " << rule.origin_port_end_
    << " " << rule.receiver_port_beg_ << " " << rule.receiver_port_end_
    << " " << rule.tcp_;
  return out;
}