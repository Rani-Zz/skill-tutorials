#include <iostream>
#include<vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
class Solution {
public:
    /**
    *从num1[m+n-1]开始赋值
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i = m-1,j = n-1;
        while(i>=0&&j>=0)
        {
            nums1[k--] = nums2[j]>=nums1[i]? nums2[j--]:nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
int main(int argc, char** argv) {
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
	Solution s;
	s.merge(nums1,3,nums2,3);
	for(auto i:nums1)
	{
		cout<<i<<" ";
	}
	
    return 0;
}