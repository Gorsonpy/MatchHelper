#include<iostream>
#include<fstream>  //文件读取写入流所用标准库
#include<string>
#include<vector>
#include"Data.h"
#include"Rule.h"

using std::cin;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

int main()
{
  string s1 = "pac.txt";
  string s2 = "rule.txt";
  vector<Data> datalist = ReadData(s1);
  vector<Rule> rulelist = ReadRule(s2);
  for (auto c : datalist)
    cout << c << endl;
  for (auto c : rulelist)
    cout << c << endl; 
  system("pause");
  return 0;
}
