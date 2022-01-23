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
  string file_name = "test.txt";
  vector<Data> datalist = ReadData(file_name);
  for (auto c : datalist)
    cout << c << endl;
  //vector<Rule> rulelist = ReadRule(file_name);
  system("pause");
  return 0;
}
