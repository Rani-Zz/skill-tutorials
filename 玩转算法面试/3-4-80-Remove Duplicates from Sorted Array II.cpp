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
    *�������ź���ģ�����kָ���±�Ϊ1��Ԫ�أ�������±�Ϊ2��Ԫ�ؿ�ʼ����
    *�Ƚ�num[i]��nums[k-1]�Ƿ���ͬ������ͬ˵����������Ѿ����ֳ��������ˣ��ҵ���ͬ����������
    *ʱ�临�Ӷ� O(n) �ռ�O(1)
    *����nums��Ԫ�ظ���������2�����
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