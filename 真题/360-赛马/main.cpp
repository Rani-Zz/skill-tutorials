#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool match(vector<int> nums,int n)
{
    sort(nums.begin(),nums.end());
    int l = 0,r = n-1;
    while(l<r)
    {
        if(nums[l]<nums[r])
        {
            l++;r--;
        }else
            return false;
    }
     
    return true;
}
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            vector<int> v(2*n,0);
            for(int i = 0;i<2*n;i++)
            {
                cin>>v[i];
            }
            bool res = match(v,2*n);
            if(res)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}