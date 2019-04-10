#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-*zero elements.
*Input: [0,1,0,3,12]
*Output: [1,3,12,0,0]
*/
class Solution {
public:
    /**
    *tow points 
    *0�Ͳ���0��Ԫ�ؽ���
    *ʱ�临�Ӷ�O(n) �ռ�O(1)
    *����û��0�����
    */
    void moveZeroes(vector<int>& nums) {
         if(nums.empty())
             return ;
        int i = 0;//nums�У�[0,...,i]��Ԫ�ؾ�Ϊ��0Ԫ��
        int j = 0;
        //��������j��Ԫ�غ󣬱�֤[0,...,j]�����з�0Ԫ��
        //������˳������[0,....,k]��
        //ͬʱ[i,...,j]Ϊ0
        for(i,j;j<nums.size();j++)
        {
            if(nums[j]!=0)
            {   if(i!=j)
                    swap(nums[i++],nums[j]);
                else //i==j
                    i++;
            }
        }
        return;
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {0,1,0,3,12};
	Solution s;
	s.moveZeroes(nums);
	for(auto i:nums)
	{
		cout<<i<<" ";
	}
    return 0;
}