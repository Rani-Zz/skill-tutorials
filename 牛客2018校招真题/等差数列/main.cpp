/**
*���һ������S����������еĺϷ���i,����S[i + 1] = S[i] + d, 
�����dҲ�����Ǹ�������,���Ǿͳ�����SΪ�Ȳ����С�
С��������һ������Ϊn������x,С�����x��Ϊһ���Ȳ����С�
С����������������������������λ�õ���ֵ�Ĳ���,
���ҽ���������������Ρ�������Щ����ͨ���������ǲ��ܱ�ɵȲ�����,
С����Ҫ�б�һ�������Ƿ���ͨ������������ɵȲ�����
*/
/**
*�뵽��˼·����������Ȼ���ٿ�����֮��Ĳ�ֵ
*��һ������impossible
*����Ļ�
*ȡ
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
