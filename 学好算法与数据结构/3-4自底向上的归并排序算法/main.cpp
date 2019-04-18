#include "SortTestHelper.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void __merge(vector<int> &nums, int l, int mid, int r)
{
	vector<int> tmp(r - l + 1,0);

	int i = l, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r)
	{
		if (nums[i] < nums[j])
		{
			tmp[k++] = nums[i++];
		}
		else {
			tmp[k++] = nums[j++];
		}
	}

	while (i <= mid)
		tmp[k++] = nums[i++];
	while (j <= r)
		tmp[k++] = nums[j++];

	for (int i = 0; i < k; i++)
	{
		nums[i + l] = tmp[i];
	}
	return;
}
void mergeSortBU(vector<int> &nums)
{
	if (nums.empty())
		return;
	int n = nums.size();
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i < n - sz; i += sz + sz)
		{
			// 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
			__merge(nums, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}
}
int main()
{
	int n = 10;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, 10);
	mergeSortBU(vec);
	SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}