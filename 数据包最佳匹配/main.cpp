#include<iostream>
#include<fstream>  //�ļ���ȡд�������ñ�׼��
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
    datalist.pop_back();  //fstream�������һ���У���������ɾ��һ�¡�
  for (auto data : datalist)
    cout << data << endl;
  system("pause");
  return 0;
}
