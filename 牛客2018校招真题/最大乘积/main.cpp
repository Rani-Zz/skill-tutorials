/**
*题目描述
*给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
*/

/**
*结果只可能有两种情况
*最大的三个数
*最大的一个和最小的两个（两负一正）
*时间复杂度O（n） 怎么才能只遍历一遍呢
*遍历一边找max1 max2 max3 min1 min2
*注意 long long
*/
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
long long maxMulti(vector<int> nums,int n)
{
    long long max1 = INT_MIN,max2 = INT_MIN,max3 = INT_MIN,min1 = INT_MAX,min2 = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        if(nums[i]<min1)
        {
            min2 = min1;
            min1 = nums[i];
        }else if(nums[i]<min2)
        {
            min2 = nums[i];
        }
        if(nums[i]>max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }else if(nums[i]>max2)
        {
            max3 = max2;
            max2 = nums[i];
        }else if(nums[i]>max3)
            max3 = nums[i];
    }
     long long res = max1*max2*max3>max1*min1*min2?max1*max2*max3:max1*min1*min2;
     return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        nums[i] = a;
    }
    
    long long res = maxMulti(nums,n);
    cout<<res<<endl;
    return 0;
}
