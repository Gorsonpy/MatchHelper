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
    string name;
    cin >> name;
    vector <Data> datalist = ReadData(name);


    cout << "���������ȫ��(����׺��),�����и���·��������Ĭ����exe����ͬ��Ŀ¼��Ѱ��."
      << endl;
    cin >> name;
    cout << "������ƥ��������ļ�ȫ��(����׺��)" << endl;
    vector<Rule> rulelist = ReadRule(name);


    cout << "1.�����и���·��������Ĭ����exe����ͬ��Ŀ¼��Ѱ��." << endl;
    cout << "2.��δ�ҵ��������ļ������Զ�����ͬ���ļ����ƥ����." << endl;
    cin >> name;

    Result_In_File(name, datalist, rulelist);
    cout << "����ƥ�����,���Բ鿴���." << endl;
    cout << "��Ҫ����ƥ�������ļ���(y or n)?" << endl;
    char c;
    cin >> c;
    if (c != 'y')
      return;
  }
}