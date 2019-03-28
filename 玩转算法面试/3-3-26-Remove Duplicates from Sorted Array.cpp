#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int k = 0;//nums中[0,...,k]为不重复的元素
        //数组是拍好序的，所以只要比较nums[i]是否等于nums[k]
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]!=nums[k])
            {    k++;
                 if(i!=k)
                    nums[k] = nums[i];                      
            }
               
        }
        return k+1;
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {1,1,2};
	Solution s;
	int res = s.removeDuplicates(nums);
	cout<<res<<endl;
    return 0;
}