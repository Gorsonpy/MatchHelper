// 用户界面函数实现

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
    cout << "请输入要检查的数据集全称(单个)，可自行给出路径，否则默认在exe程序同级目录下寻找."
      << endl;
    string name;
    cin >> name;
    vector <Data> datalist = ReadData(name);


    cout << "请输入规则集全称(带后缀名),可自行给出路径，否则默认在exe程序同级目录下寻找."
      << endl;
    cin >> name;
    cout << "请输入匹配结果存放文件全称(带后缀名)" << endl;
    vector<Rule> rulelist = ReadRule(name);


    cout << "1.可自行给出路径，否则默认在exe程序同级目录下寻找." << endl;
    cout << "2.若未找到该名称文件，会自动创建同名文件存放匹配结果." << endl;
    cin >> name;

    Result_In_File(name, datalist, rulelist);
    cout << "尝试匹配完成,可以查看结果." << endl;
    cout << "还要继续匹配其他文件吗(y or n)?" << endl;
    char c;
    cin >> c;
    if (c != 'y')
      return;
  }
}