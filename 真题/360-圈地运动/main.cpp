#include<iostream>
#include<vector>
using namespace std;
int count(vector<int> nums,int n)
{
    if(nums.empty())
        return -1;
    if(n<3)
        return -1;
    int sum = nums[0]+nums[1];
    int max = nums[0]>nums[1]?nums[0]:nums[1];
    for(int i = 2;i<n;i++)
    {
        if(nums[i]>max)
        {
            max = nums[i];
        }
        sum+=nums[i];
        if(sum-max>max)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> a(n,0);
        for(int i = 0;i<n;i++)
            cin>>a[i];
        int res = count(a,n);
        cout<<res<<endl;
    }
    return 0;
}