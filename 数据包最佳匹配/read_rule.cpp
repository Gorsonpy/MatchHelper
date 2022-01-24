#include<iostream>
#include<fstream>
#include<string>
#include"Rule.h"

using std::string;
using std::vector;
using std::fstream;



uint32_t uint_pow(uint32_t c, uint32_t e) //乘方函数
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

uint32_t TransIp(string s) //ip地址转化为十进制数字
{
  uint32_t ans = 0, curr = 0, base = 24;
  for (auto c : s)
  {
    if (c == '.')
    {
      ans += curr * uint_pow(2, base);
      curr = 0;
      base -= 8;
    }
    else
      curr = curr * 10 + c - 48;
  }
  ans += curr; //最后还要加上一次
  return ans;
}

void div_str(string& ip)  //分离ip里多余的位数信息
{
  auto it = ip.begin();
  while (it != ip.end())
  {
    if (*it == '/')
    {
      ip.erase(it, ip.end());
      break;
    }
    else
      ++it;
  }
}

vector<Rule> ReadRule(string &file_name)
{
  ifstream fin(file_name);
  vector<Rule> rulelist;
  string ip1, ip2;
  uint32_t port1_beg = 0, port1_end = 0, port2_beg = 0, port2_end = 0,
    tcp = 0;

  //以下分离两ip地址
  while (!fin.eof() && fin.peek() != EOF)
  {
    char font = '\0';
    fin >> font;
    if (font == '\0')  //监测是否是最后一个空行
      break;
    fin >> ip1 >> ip2;
    div_str(ip1);
    div_str(ip2);

    //以下分离端口
    char other = '\0';
    fin >> port1_beg >> other >> port1_end;
    fin >> port2_beg >> other >> port2_end;

    //以下分离tcp端口值
    string str_tcp;
    fin >> str_tcp;
    if (str_tcp[7] == 'F' && str_tcp[8] == 'F')
      tcp = 16 * (str_tcp[2] - 48) + str_tcp[3] - 48;
    else if (str_tcp[7] == '0' && str_tcp[8] == '0')
      tcp = 256;      // 两位数十六进制的最大值为1111 1111 = 255
    //特殊标记,表示可以匹配所有协议号

    Rule rule(TransIp(ip1), TransIp(ip2), port1_beg, port1_end, port2_beg,
      port2_end, tcp);
    rulelist.push_back(rule);
  }
  fin.close();
  return rulelist;
}