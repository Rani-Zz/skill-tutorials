#include "SortTestHelper.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int __inverseCountMerge(vector<int> &nums, int l, int mid, int r)
{
	vector<int> tmp(r - l + 1, 0);
	int i = l, j = mid + 1;
	int count = 0;
	int k = 0;
	while (i <= mid && j <= r)
	{
		if (nums[i] < nums[j])
		{
			tmp[k++] = nums[i++];
		}
		else {
			tmp[k++] = nums[j++];
			count += mid-i+1;
		}
	}
	while (i <= mid)
		tmp[k++] = nums[i++];
	while (j <= r)
		tmp[k++] = nums[j++];
	for (int i = 0; i < k; i++)
	{
		nums[l + i] = tmp[i];
	}

	return count;
}
int __inverseCount(vector<int> &nums,int l,int r)
{
	if (l >= r) return 0;
	int res = 0;
	int mid = (l + r) / 2;
	res += __inverseCount(nums, l, mid);
	res += __inverseCount(nums, mid + 1, r);
	res += __inverseCountMerge(nums, l, mid, r);

	return res;
}
int inverseCount(vector<int> &nums)
{
	if (nums.empty())
		return 0;
	int n = nums.size();
	return __inverseCount(nums, 0, n - 1);
}
int main()
{
	vector<int> nums = { 9,8,7,6,5,4,3,2,1 };
	int res = inverseCount(nums);
	cout << res << endl;
	//mergeSortBU(vec);
	//SortTestHelper::testSort("quickSort3ways", quickSort3ways, vec);
	//SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}