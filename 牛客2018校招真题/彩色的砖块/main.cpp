/**
题目描述
小易有一些彩色的砖块。每种颜色由一个大写字母表示。各个颜色砖块看起来都完全一样。现在有一个给定的字符串s,s中每个字符代表小易的某个砖块的颜色。小易想把他所有的砖块排成一行。如果最多存在一对不同颜色的相邻砖块,那么这行砖块就很漂亮的。请你帮助小易计算有多少种方式将他所有砖块排成漂亮的一行。(如果两种方式所对应的砖块颜色序列是相同的,那么认为这两种方式是一样的。)
例如: s = "ABAB",那么小易有六种排列的结果:
"AABB","ABAB","ABBA","BAAB","BABA","BBAA"
其中只有"AABB"和"BBAA"满足最多只有一对不同颜色的相邻砖块。
*/

/**
*最多存在不对不同颜色的相邻砖块
*所以只要超过2两类型就不可能满足了 直接返回0
*如果有两种返回2
*只有一种返回1
*我想的是用set
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
