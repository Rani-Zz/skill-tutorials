/**
*如果最大的比连个其他两个加起来的两倍大，那么就可以用 1 2这种，最多的会与欧剩余
*如果没有则 先1 1 1，剩下的1 2,3个一组就可以了
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            vector<long long> nums(3,0);
            for(int i = 0;i<3;i++)
                cin>>nums[i];
            sort(nums.begin(),nums.end());
            if(nums[2]>(nums[0]+nums[1])*2)
                cout<<nums[0]+nums[1]<<endl;
            else
                cout<<(nums[0]+nums[1]+nums[2])/3<<endl;
        }
    }
    return 0;
}