#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    /**
    *two pints
    *数组是排好序的，所以k指向下标为1的元素，数组从下标为2的元素开始遍历
    *比较num[i]和nums[k-1]是否相同，若相同说明这个数字已经出现超过两次了，找到不同的数覆盖它
    *时间复杂度 O(n) 空间O(1)
    *考虑nums中元素个数不超过2的情况
    */
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()<=2)
            return nums.size();
        int k = 1;
        for(int i = 2;i<nums.size();i++)
        {
            if(nums[i]!=nums[k-1])
                nums[++k] = nums[i];
        }
        return k+1;
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {1,1,1,2,2,3};
	Solution s;
	int res = s.removeDuplicates(nums);
	cout<<res<<endl;
    return 0;
}