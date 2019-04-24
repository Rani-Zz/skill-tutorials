#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>
#define INT_MAX 2147483647
using namespace std;


/*
AC100%
小明家有一些彩球，一段时间后小明玩耍时将它们无序的散落在家中，一天，
小明想对其进行整理，规则为一个篮子中只放一种颜色彩球，
可有多个篮子放同一颜色的球，每个篮子里的球不少于2个。
假设小明整理好后，能使各篮子中彩球数量是相同的，
则认为小明整理好了。用一个数字表示一种颜色彩球，
一组数表示小明已经找到了的彩球，问小明用找到的全部彩球能按规则整理好么？

第一行彩球总数: n,  2<n<10000

第二行一段整数ai,  1<ai<10000  (排除ai全部相等的情况)

若能整理好，最小篮子数；否则0

6
1 1 2 2 2 2

3

请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int fun(vector<int> nums) {
    if(nums.empty())
        return 0;
    map<int,int> map;
    for(int i=0;i<nums.size();i++)
    {
            map[nums[i]]++;
    }
    
    int minSize = INT_MAX;
    for(auto m:map)
    {
    	minSize = min(minSize,m.second);
	}
	
	if(minSize==1)
	    return 0;
	
	int res = 0;
	
	for(auto m:map)
    {
    	if(m.second%minSize!=0)
    	     return 0;
        else
           res += m.second/minSize;
	}
	
	return res;

}
/******************************结束写代码******************************/


int main() {
    int res; 
    int n;
    while(cin>>n)
        {
            vector<int> nums(n,0);
            int a;
            for(int i = 0;i<n;i++)
                {
                    cin>>a;
                    nums[i] = a;
                }
             res = fun(nums);
             cout << res << endl;
        }
    
   
    
    return 0;

}
