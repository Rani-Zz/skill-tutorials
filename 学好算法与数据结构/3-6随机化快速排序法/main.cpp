#include "stdafx.h"
#include "SortTestHelper.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/**
*快速排序在有序的情况下 退化为O(n^2) 
*当每次的标定l都是最小的数进行partition时，
*左边没有，只有右边，这样就变成了O(n^2)
*改进方式,选标定时选[l,...,r]之间的随机值
*随机化的方案，让快速排序的近乎有序的情况下，加快速度
*/

//返回p，使得[l,...,p-1]<nums[p] [p+1,...,r]>nums[p]
int __partition(vector<int> &nums, int l, int r)
{
	//[l+1,...,j]<v [j+1,...,r]>v
	swap(nums[l], nums[rand() % (r - l + 1) + l]);
	int v = nums[l];
	int j = l;

	for (int i = l + 1; i <= r; i++)
	{
		if (nums[i] > v)
		{
			swap(nums[j + 1], nums[i]);
			j++;
		}
	}
	swap(nums[l], nums[j]);
	return j;
}
void __quickSort1(vector<int> &nums, int l, int r)
{
	if (l >= r)
		return;
	
	int p = __partition(nums, l, r);
	__quickSort1(nums, l, p - 1);
	__quickSort1(nums, p + 1, r);

	return;
}
void quickSort1(vector<int> &nums)
{
	if (nums.empty())
		return;
	int n = nums.size();
	srand(time(NULL));
	__quickSort1(nums, 0, n - 1);
	return;
}

int main()
{
	int n = 1000;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, n);
	//mergeSortBU(vec);
	quickSort1(vec);
	SortTestHelper::testSort("quickSort1", quickSort1, vec);
	//SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}