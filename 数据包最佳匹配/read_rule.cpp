#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<algorithm>
#include"Rule.h"

using std::string;
using std::vector;
using std::fstream;
using std::pair;
using ll = long long;
using PII = pair<ll, ll>;


long long qpower(ll a, ll b)
{
  ll basic = a, ans = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      ans *= basic;
    }
    basic *= basic;
    b >>= 1;
  }
  return ans;
}
//这里函数不传引用，因为不能从逻辑上不应更改传入的字符串
PII StrBin_To_Dec(string &str_bin, ll bit) //把二进制的字符串转化为十进制
//返回一个最小地址ip和最大地址ip的二元组
{
  PII min_max;
  ll num = 0;
  int base = 31; //基准，即2的次方数
  

  for (int i = 0; i < bit; ++i)  //第bit位之前的正常按照二进制计算
  {
    ll curr = 0;
    if (str_bin[i] == '1')
    {
      curr = qpower(2, base);
    }
    num += curr;
    --base;
  }
  
  min_max.first = num;  //最小值就是后面全置为0，无需计算
  
  for (int i = bit; i < str_bin.size(); ++i)
  {
    //最大值就是后面全为1
    num += qpower(2, base);
    --base;
  }
  min_max.second = num;

  return min_max;
}

string Dec_To_Bin(ll num) //接受一个数字，并把它转化为八位二进制数字形式的字符串
{
  string str_bin = "00000000"; //初始八位都置0
  for (int i = 7; i >= 0; --i)
  {
    str_bin[i] = num % 2 + 48;
    num >>= 1;
  }
  return str_bin;
}


void TransCidr(string& cidr, int cnt[]) //把cidr地址分为五个部分十进制数字
// 存放在传入的数组
{
  auto iter = cidr.begin();
  ll i = 0; //数组的下标
  while (iter != cidr.end()) //遍历字符串
  {
    while (iter != cidr.end() && *iter != '.' && *iter != '/')
    {
      cnt[i] = 10 * cnt[i] + (*iter) - 48;  //计算每个个部分的十进制数字大小
      ++iter;
    }
    //跳出内层循环就代表读到了'.' 或 '/' 或末尾

    //如果读到末尾要把最后一个位置数字加上
    if (*iter == '/')
    {
      ++iter;
      while (iter != cidr.end())
      {
        cnt[4] = 10 * cnt[4] + (*iter) - 48;
        ++iter;
      }
      return;
    }
    else
      ++iter, ++i;
  }
}


vector<Rule> ReadRule(string &file_name)
{
  ifstream fin(file_name);
  vector<Rule> rulelist;
  ll port1_beg = 0, port1_end = 0, port2_beg = 0, port2_end = 0,
    tcp = 0;

  //以下分离两ip地址
  while (!fin.eof() && fin.peek() != EOF)
  {
    char other = '\0';
    fin >> other; //除去开头的'@'字符
    if (other == '\0')  //监测是否是最后一个空行
      break;


    string cidr1, cidr2;  //cidr 地址
    fin >> cidr1 >> cidr2;
    int cnt1[5] = { 0, 0, 0, 0, 0 }; //分别存放五个部分的数字
    int cnt2[5] = { 0, 0, 0, 0, 0};
    TransCidr(cidr1, cnt1), TransCidr(cidr2, cnt2); // 分离ip地址的五个部分在cnt1和cnt2
    string str_bin1, str_bin2;
    for (int i = 0; i < 4; ++i) //前四个位置是ip信息
    {
      str_bin1 += Dec_To_Bin(cnt1[i]);
    }
    
    PII ip1 = StrBin_To_Dec(str_bin1, cnt1[4]);

    for (int i = 0; i < 4; ++i)
    {
      str_bin2 += Dec_To_Bin(cnt2[i]);
    }

    PII ip2 = StrBin_To_Dec(str_bin2, cnt2[4]);


    //以下分离端口范围值
    fin >> port1_beg >> other >> port1_end;
    fin >> port2_beg >> other >> port2_end;

    //以下分离tcp范围值
    string str_tcp;
    fin >> str_tcp;
    if (str_tcp[7] == 'F' && str_tcp[8] == 'F')
      tcp = 16 * (str_tcp[2] - 48) + str_tcp[3] - 48;
    else if (str_tcp[7] == '0' && str_tcp[8] == '0')
      tcp = 256;      // 两位数十六进制的最大值为1111 1111 = 255
    //特殊标记,表示可以匹配所有协议号
    Rule rule(ip1.first, ip1.second, ip2.first, ip2.second, port1_beg, port1_end,
      port2_beg, port2_end, tcp);
    rulelist.push_back(rule);
  }
  fin.close();
  return rulelist;
}