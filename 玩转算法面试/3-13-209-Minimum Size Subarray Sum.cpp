#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Share
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0,sum = 0,res = INT_MAX;
        while(r<nums.size())
        {
            sum+=nums[r++];
            while(sum>=s)
            {
                res = min(res,r-l);
                sum-=nums[l++];
            }
        }
        return res==INT_MAX?0:res;
    }
};
int main(int argc, char** argv) {
	vector<int> nums ={2,3,1,2,4,3};
	Solution s;
	int res = s.minSubArrayLen(7,nums);
	cout<<res;
	
    return 0;
}