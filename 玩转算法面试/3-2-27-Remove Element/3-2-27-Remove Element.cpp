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
        int k = 0;//nums��,[0,...,k]Ϊ��val��Ԫ��
        //��������iԪ��ʱҪ��֤[0,...,i]�еķ�valԪ����[0,...,k]��
        //����k+1��Ϊ�³���
        //����Ҫ�����Ƴ�
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                if(i!=k)
                    swap(nums[i],nums[k++]);//���nums�ж���Ϊval��Ԫ���������������Ż�
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