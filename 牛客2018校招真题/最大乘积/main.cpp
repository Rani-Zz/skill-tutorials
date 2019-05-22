/**
*��Ŀ����
*����һ���������飬����������������0��Ҫ������ҳ�3�����ĳ˻���ʹ�ó˻����Ҫ��ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)
*/

/**
*���ֻ�������������
*����������
*����һ������С������������һ����
*ʱ�临�Ӷ�O��n�� ��ô����ֻ����һ����
*����һ����max1 max2 max3 min1 min2
*ע�� long long
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
