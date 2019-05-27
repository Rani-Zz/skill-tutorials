/**
��Ŀ����
���һ��01��������������λ�õ��ַ����ǲ�һ����,
���Ǿͽ����01��Ϊ����01��������: "1","10101","0101010"���ǽ���01����
С��������һ��01��s,С�����ҳ�һ����������Ӵ�,��������Ӵ���һ������01����
С����Ҫ����æ�������������Ӵ��ĳ����Ƕ��١�
*/
/**
*ʱ��O(n)�ռ�O(n)
*dp[i��ʾ��i��β����Ӵ�
*dp[i] = ��ǰһλ��ͬ dp[i-1]+1,����1
*����ҳ����ֵ
*�ռ�O(1)cur max����������¼����󷵻�max
*/
#include<iostream>
#include<limits>
#include<cmath>
using namespace std;
int longestSubstring(string s)
{
    int cur = 1;
    int res = cur;
    for(int i = 1;i<s.size();i++)
    {
        cur = (s[i-1]-'0')^(s[i]-'0')?cur+1:1;
        res = max(res,cur);
    }
    
    return res;
}
int main()
{
    string s;
    cin>>s;
    int res = longestSubstring(s);
    cout<<res<<endl;
    return 0;
}
