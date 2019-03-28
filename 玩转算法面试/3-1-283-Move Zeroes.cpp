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
    *0和不是0的元素交换
    *时间复杂度O(n) 空间O(1)
    *考虑没有0的情况
    */
    void moveZeroes(vector<int>& nums) {
         if(nums.empty())
             return ;
        int i = 0;//nums中，[0,...,i]的元素均为非0元素
        int j = 0;
        //遍历到第j个元素后，保证[0,...,j]中所有非0元素
        //都按照顺序排在[0,....,k]中
        //同时[i,...,j]为0
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