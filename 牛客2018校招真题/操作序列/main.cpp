/**
��Ŀ����
С����һ������Ϊn����������,a_1,...,a_n��Ȼ������һ��������b�Ͻ���n�����²���:
1����a_i����b���е�ĩβ
2������b����
С����Ҫ������������n��֮���b���С�
*/
/**
*��������ɵĻ� ʱ��O(n^2)�϶��ᳬʱ
*��Ȼ���˿����ҵ����� Ϊʲô��û��
*������
*n = 1,b = 1    n = 1ֱ�����
*n = 2,b = 2,1
*n = 3,b = 3,1,2
*n = 4,b = 4,2,1,3
*n = 5,b = 5,3,1,2,4
*n = 6,b = 6,4,2,1,3,5
*���������ƣ���n Ϊ����ʱ��
*�ȴӺ���ǰ�������λ�õ����֣��ٴ�ǰ������ż��λ�õ����� 
*��n Ϊż��ʱ
*�ȴӺ���ǰ���ż��λ�õ����֣��ٴ�ǰ����������λ�õ�����
*��������O��n��
*/
#include<iostream>
#include<vector>
using namespace std;
void fun(vector<int> nums,int n)
{
    if(n%2==1)//nΪ����
    {
        for(int i = n;i>=1;i-=2) //��������
            cout<<nums[i]<<" ";
        for(int i = 2;i<=n;i+=2) //ż������
        {
            cout<<nums[i];
            if(i!=n)
                cout<<" ";
        }
    }else{        //nΪż��

        for(int i = n;i>=2;i-=2) //ż������
            cout<<nums[i]<<" ";
        for(int i = 1;i<=n-1;i+=2)//��������
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
    //�±��1��ʼ
    for(int i = 1;i<=n;i++)
    {
        int a;
        cin>>a;
        nums[i] = a;
    }
    
    fun(nums,n);
    return 0;
}
