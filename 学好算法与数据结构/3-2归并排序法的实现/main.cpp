#include "SortTestHelper.h"
#include<iostream>
#include<vector>

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
void __mergeSort(vector<int> &nums, int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	__mergeSort(nums, l, mid);
	__mergeSort(nums, mid + 1, r);
	__merge(nums, l, mid, r);
}
void mergeSort(vector<int> &nums)
{
	int n = nums.size();
	__mergeSort(nums, 0, n - 1);
}
int main()
{
	int n = 10;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, 10);
	mergeSort(vec);
	SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}