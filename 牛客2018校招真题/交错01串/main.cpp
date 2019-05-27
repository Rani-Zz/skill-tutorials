/**
题目描述
如果一个01串任意两个相邻位置的字符都是不一样的,
我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。
小易需要你帮帮忙求出最长的这样的子串的长度是多少。
*/
/**
*时间O(n)空间O(n)
*dp[i表示以i结尾的最长子串
*dp[i] = 与前一位不同 dp[i-1]+1,否则1
*最后找出最大值
*空间O(1)cur max两个变量记录，最后返回max
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
