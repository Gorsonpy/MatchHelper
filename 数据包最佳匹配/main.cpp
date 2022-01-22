#include<iostream>
#include<fstream>  //文件读取写入流所用标准库
#include<string>
#include<vector>
#include"Data.h"

using std::cin;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

int main()
{
  string file_name = "packet1.txt";
  vector<Data> datalist = Read(file_name);
  if (datalist.size() > 1)
    datalist.pop_back();  //fstream会多读最后一空行，这里特判删除一下。
  for (auto data : datalist)
    cout << data << endl;
  system("pause");
  return 0;
}
