#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<algorithm>
#include"Rule.h"

using std::string;
using std::vector;
using std::fstream;
using std::pair;
using ll = long long;
using PII = pair<ll, ll>;


long long qpower(ll a, ll b)
{
  ll basic = a, ans = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      ans *= basic;
    }
    basic *= basic;
    b >>= 1;
  }
  return ans;
}
//���ﺯ���������ã���Ϊ���ܴ��߼��ϲ�Ӧ���Ĵ�����ַ���
PII StrBin_To_Dec(string &str_bin, ll bit) //�Ѷ����Ƶ��ַ���ת��Ϊʮ����
//����һ����С��ַip������ַip�Ķ�Ԫ��
{
  PII min_max;
  ll num = 0;
  int base = 31; //��׼����2�Ĵη���
  

  for (int i = 0; i < bit; ++i)  //��bitλ֮ǰ���������ն����Ƽ���
  {
    ll curr = 0;
    if (str_bin[i] == '1')
    {
      curr = qpower(2, base);
    }
    num += curr;
    --base;
  }
  
  min_max.first = num;  //��Сֵ���Ǻ���ȫ��Ϊ0���������
  
  for (int i = bit; i < str_bin.size(); ++i)
  {
    //���ֵ���Ǻ���ȫΪ1
    num += qpower(2, base);
    --base;
  }
  min_max.second = num;

  return min_max;
}

string Dec_To_Bin(ll num) //����һ�����֣�������ת��Ϊ��λ������������ʽ���ַ���
{
  string str_bin = "00000000"; //��ʼ��λ����0
  for (int i = 7; i >= 0; --i)
  {
    str_bin[i] = num % 2 + 48;
    num >>= 1;
  }
  return str_bin;
}


void TransCidr(string& cidr, int cnt[]) //��cidr��ַ��Ϊ�������ʮ��������
// ����ڴ��������
{
  auto iter = cidr.begin();
  ll i = 0; //������±�
  while (iter != cidr.end()) //�����ַ���
  {
    while (iter != cidr.end() && *iter != '.' && *iter != '/')
    {
      cnt[i] = 10 * cnt[i] + (*iter) - 48;  //����ÿ�������ֵ�ʮ�������ִ�С
      ++iter;
    }
    //�����ڲ�ѭ���ʹ��������'.' �� '/' ��ĩβ

    //�������ĩβҪ�����һ��λ�����ּ���
    if (*iter == '/')
    {
      ++iter;
      while (iter != cidr.end())
      {
        cnt[4] = 10 * cnt[4] + (*iter) - 48;
        ++iter;
      }
      return;
    }
    else
      ++iter, ++i;
  }
}


vector<Rule> ReadRule(string &file_name)
{
  ifstream fin(file_name);
  vector<Rule> rulelist;
  ll port1_beg = 0, port1_end = 0, port2_beg = 0, port2_end = 0,
    tcp = 0;

  //���·�����ip��ַ
  while (!fin.eof() && fin.peek() != EOF)
  {
    char other = '\0';
    fin >> other; //��ȥ��ͷ��'@'�ַ�
    if (other == '\0')  //����Ƿ������һ������
      break;


    string cidr1, cidr2;  //cidr ��ַ
    fin >> cidr1 >> cidr2;
    int cnt1[5] = { 0, 0, 0, 0, 0 }; //�ֱ���������ֵ�����
    int cnt2[5] = { 0, 0, 0, 0, 0};
    TransCidr(cidr1, cnt1), TransCidr(cidr2, cnt2); // ����ip��ַ�����������cnt1��cnt2
    string str_bin1, str_bin2;
    for (int i = 0; i < 4; ++i) //ǰ�ĸ�λ����ip��Ϣ
    {
      str_bin1 += Dec_To_Bin(cnt1[i]);
    }
    
    PII ip1 = StrBin_To_Dec(str_bin1, cnt1[4]);

    for (int i = 0; i < 4; ++i)
    {
      str_bin2 += Dec_To_Bin(cnt2[i]);
    }

    PII ip2 = StrBin_To_Dec(str_bin2, cnt2[4]);


    //���·���˿ڷ�Χֵ
    fin >> port1_beg >> other >> port1_end;
    fin >> port2_beg >> other >> port2_end;

    //���·���tcp��Χֵ
    string str_tcp;
    fin >> str_tcp;
    if (str_tcp[7] == 'F' && str_tcp[8] == 'F')
      tcp = 16 * (str_tcp[2] - 48) + str_tcp[3] - 48;
    else if (str_tcp[7] == '0' && str_tcp[8] == '0')
      tcp = 256;      // ��λ��ʮ�����Ƶ����ֵΪ1111 1111 = 255
    //������,��ʾ����ƥ������Э���
    Rule rule(ip1.first, ip1.second, ip2.first, ip2.second, port1_beg, port1_end,
      port2_beg, port2_end, tcp);
    rulelist.push_back(rule);
  }
  fin.close();
  return rulelist;
}