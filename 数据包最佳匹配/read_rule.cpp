#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include"Rule.h"

using std::string;
using std::reverse;
using std::vector;
using std::fstream;

uint32_t uint_pow(uint32_t c, uint32_t e)
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
    base *= uint_pow(2, 8);
  }
  return ans;
}

vector<Rule> ReadRule(string& file_name)
{
  ifstream fin(file_name);
  vector<Rule> rulelist;
  char other = '\0';
  string 
  while (!fin.eof() && fin.peek() != EOF)
  {
    
  }
  
  fin.close();
  return rulelist;
}