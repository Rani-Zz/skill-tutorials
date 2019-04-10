#include <iostream>
#include<vector>
#include<queue>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
*/
class Solution {
public:
    /**
    *sort() ʱ�临�Ӷ�o(nlogn)
    *�ռ临�Ӷ�o(1)
    *�����ȶ��� ʱ�临�Ӷ�O(nlogk) ��С��
    *�ռ临�Ӷ� O(k)
    */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto i:nums)
        {
            if(pq.size()!=k)
                pq.push(i);
            else if(i>pq.top())
            {
                pq.pop();
                pq.push(i);
            }
        }
        return pq.top();
    }
};
int main(int argc, char** argv) {
	vector<int> nums = {3,2,1,5,6,4};
	Solution s;
	int res = s.findKthLargest(nums,2);
	cout<<res;
	
    return 0;
}