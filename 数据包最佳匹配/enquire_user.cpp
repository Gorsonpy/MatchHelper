// �û����溯��ʵ��

#include<iostream>
#include<string>
#include"match_util.h"
#include"Data.h"
#include"Rule.h"

using std::cin;
using std::endl;
using std::string;

void EnquireUser()
{
  while (1)
  {
    cout << "������Ҫ�������ݼ�ȫ��(����)�������и���·��������Ĭ����exe����ͬ��Ŀ¼��Ѱ��."
      << endl;
    string name1;
    cin >> name1;
    vector <Data> datalist = ReadData(name1);


    cout << "���������ȫ��(����׺��),�����и���·��������Ĭ����exe����ͬ��Ŀ¼��Ѱ��."
      << endl;
    string name2;
    cin >> name2;
    vector<Rule> rulelist = ReadRule(name2);

    string ans_name = "res.txt";
    Result_In_File(ans_name, datalist, rulelist, name1);
    cout << "����ƥ�����,���Բ鿴���." << endl;
    cout << "��Ҫ����ƥ�������ļ���(y or n)?" << endl;
    char c;
    cin >> c;
    if (c != 'y')
      return;
  }
}