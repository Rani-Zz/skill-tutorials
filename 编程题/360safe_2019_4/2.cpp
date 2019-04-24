#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>
#define INT_MAX 2147483647
using namespace std;


/*
AC100%
С������һЩ����һ��ʱ���С����ˣʱ�����������ɢ���ڼ��У�һ�죬
С������������������Ϊһ��������ֻ��һ����ɫ����
���ж�����ӷ�ͬһ��ɫ����ÿ���������������2����
����С������ú���ʹ�������в�����������ͬ�ģ�
����ΪС��������ˡ���һ�����ֱ�ʾһ����ɫ����
һ������ʾС���Ѿ��ҵ��˵Ĳ�����С�����ҵ���ȫ�������ܰ����������ô��

��һ�в�������: n,  2<n<10000

�ڶ���һ������ai,  1<ai<10000  (�ų�aiȫ����ȵ����)

��������ã���С������������0

6
1 1 2 2 2 2

3

������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
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
/******************************����д����******************************/


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
