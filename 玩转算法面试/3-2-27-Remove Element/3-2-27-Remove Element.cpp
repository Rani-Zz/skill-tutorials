#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        int k = 0;//nums中,[0,...,k]为非val的元素
        //遍历到第i元素时要保证[0,...,i]中的非val元素在[0,...,k]中
        //这样k+1即为新长度
        //不需要真正移除
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                if(i!=k)
                    swap(nums[i],nums[k++]);//如果nums中都不为val则元素自身交换，所以优化
                else
                    k++;
            }
        }
        return k;
        
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {3,2,2,3};
	Solution s;
	int res = s.removeElement(nums,3);
	cout<<res<<endl;
    return 0;
}