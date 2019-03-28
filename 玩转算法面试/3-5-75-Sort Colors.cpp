#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.
Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
class Solution {
public:
    /**
    *numsÖÐ[0,...,zero]Îª0£¬[two,....,n-1]Îª2
    *two points
    */
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return ;
        int zero = -1,two = nums.size();
        for(int i = 0;i<two;)
        {
            
            if(nums[i]==0)
                swap(nums[++zero],nums[i]);
            if(nums[i]==2)
                swap(nums[--two],nums[i]);
            else
                i++;
        }
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {2,0,2,1,1,0};
	Solution s;
	s.sortColors(nums);
	for(auto i:nums)
	{
		cout<<i<<" ";
	}
	
    return 0;
}