#include<iostream>
#include<fstream>  //文件读取写入流所用标准库
#include<string>
#include<vector>
#include"Data.h"
#include"Rule.h"
#include"match_util.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;

int main()
{
  string name1 = "packet1.txt";
  string name2 = "rule1.txt";
  string name3 = "ans.txt";

  
  vector<Data> datalist = ReadData(name1);
  vector<Rule> rulelist = ReadRule(name2);

  WriteInFile(name3, datalist, rulelist);
  system("pause");
  return 0;
}
