/**
题目描述
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列。
*/
/**
*按操作完成的话 时间O(n^2)肯定会超时
*果然别人可以找到规律 为什么我没有
*规律题
*n = 1,b = 1    n = 1直接输出
*n = 2,b = 2,1
*n = 3,b = 3,1,2
*n = 4,b = 4,2,1,3
*n = 5,b = 5,3,1,2,4
*n = 6,b = 6,4,2,1,3,5
*由上述可推，当n 为奇数时，
*先从后向前输出奇数位置的数字，再从前向后输出偶数位置的数字 
*当n 为偶数时
*先从后向前输出偶数位置的数字，再从前向后输出奇数位置的数字
*这样做是O（n）
*/
#include<iostream>
#include<vector>
using namespace std;
void fun(vector<int> nums,int n)
{
    if(n%2==1)//n为奇数
    {
        for(int i = n;i>=1;i-=2) //奇数倒序
            cout<<nums[i]<<" ";
        for(int i = 2;i<=n;i+=2) //偶数正序
        {
            cout<<nums[i];
            if(i!=n)
                cout<<" ";
        }
    }else{        //n为偶数

        for(int i = n;i>=2;i-=2) //偶数倒序
            cout<<nums[i]<<" ";
        for(int i = 1;i<=n-1;i+=2)//奇数正序
        {
            cout<<nums[i];
            if(i!=n-1)
                cout<<" ";
        }
    }
    cout<<endl;
    return ;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n+1,0);
    //下标从1开始
    for(int i = 1;i<=n;i++)
    {
        int a;
        cin>>a;
        nums[i] = a;
    }
    
    fun(nums,n);
    return 0;
}
