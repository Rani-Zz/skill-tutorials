#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            vector<int> nums(5,0);
            int sum = 0;
            for(int i = 0;i<5;i++)
            {
                cin>>nums[i];
                sum+=nums[i];
            }
            if(sum==0)
                cout<<-1<<endl;
            else if(sum%5==0)
                cout<<sum/5<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}