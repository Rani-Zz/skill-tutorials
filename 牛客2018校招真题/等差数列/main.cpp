/**
*如果一个数列S满足对于所有的合法的i,都有S[i + 1] = S[i] + d, 
这里的d也可以是负数和零,我们就称数列S为等差数列。
小易现在有一个长度为n的数列x,小易想把x变为一个等差数列。
小易允许在数列上做交换任意两个位置的数值的操作,
并且交换操作允许交换多次。但是有些数列通过交换还是不能变成等差数列,
小易需要判别一个数列是否能通过交换操作变成等差数列
*/
/**
*想到的思路就是先排序然后再看两个之间的差值
*不一样就是impossible
*排序的话
*取
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool judge(vector<int> nums,int n)
{
    if(n<=2) return true;
    sort(nums.begin(),nums.end());
    int diff = nums[1]-nums[0];
    for(int i = 2;i<n;i++)
    {
        if(diff!=nums[i]-nums[i-1])
            return false;
    }
    
    return true;
    
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
    bool res = judge(nums,n);
    if(res)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}
