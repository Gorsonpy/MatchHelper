#include<iostream>
#include<fstream>  //�ļ���ȡд�������ñ�׼��
#include<string>
#include"Data.h"
using std::cin;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using ll = long long;
int main()
{
  string file_name = "packet1.txt";
  
  Data test_data;
  Read(file_name, test_data);
  print(cout, test_data);
  Read(file_name, test_data);
  print(cout, test_data);
  return 0;
}
