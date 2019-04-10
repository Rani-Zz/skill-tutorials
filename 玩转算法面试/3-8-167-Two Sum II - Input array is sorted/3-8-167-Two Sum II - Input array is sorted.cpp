#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       /*¶Ô×²Ö¸Õë*/
       int l = 0, r = numbers.size()-1;
       vector<int> res;
       while(l<r)
       {
           if(numbers[l]+numbers[r]==target)
           {
               res.push_back(l+1);
               res.push_back(r+1);
               break;
           }else if(numbers[l]+numbers[r]<target)
               l++;
           else
               r--;
       }
        return res;
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {2,7,11,15};
	Solution s;
	vector<int> res = s.twoSum(nums,9);

	for(auto i:res)
	{
		cout<<i<<" ";
	}
	
    return 0;
}