/**
��Ŀ����
С����һЩ��ɫ��ש�顣ÿ����ɫ��һ����д��ĸ��ʾ��������ɫש�鿴��������ȫһ����������һ���������ַ���s,s��ÿ���ַ�����С�׵�ĳ��ש�����ɫ��С����������е�ש���ų�һ�С����������һ�Բ�ͬ��ɫ������ש��,��ô����ש��ͺ�Ư���ġ��������С�׼����ж����ַ�ʽ��������ש���ų�Ư����һ�С�(������ַ�ʽ����Ӧ��ש����ɫ��������ͬ��,��ô��Ϊ�����ַ�ʽ��һ���ġ�)
����: s = "ABAB",��ôС�����������еĽ��:
"AABB","ABAB","ABBA","BAAB","BABA","BBAA"
����ֻ��"AABB"��"BBAA"�������ֻ��һ�Բ�ͬ��ɫ������ש�顣
*/

/**
*�����ڲ��Բ�ͬ��ɫ������ש��
*����ֻҪ����2�����;Ͳ����������� ֱ�ӷ���0
*��������ַ���2
*ֻ��һ�ַ���1
*���������set
*/
#include<iostream>
#include<set>
using namespace std;
int comWays(string s)
{
    set<char> set;
    for(auto c:s)
    {
        set.insert(c);
        if(set.size()>2)
            return 0;
    }
    
    if(set.size()==2)
        return 2;
    else if(set.size()==1)
        return 1;
    else
        return 0;
}
int main()
{
    string s;
    cin>>s;
    int res = comWays(s);
    cout<<res<<endl;
    return 0;
}
