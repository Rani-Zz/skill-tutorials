#include "SortTestHelper.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template <typename T>
void instertSort(vector<T> &nums,int l,int r)
{
	if (nums.empty())
		return;
	for (int i = l; i <=r; i++)
	{
		int temp = nums[i];
		int j = i;
		while (j > 0 && nums[j - 1] > temp)
		{
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = temp;
	}
	return;
}
/**
*如果partiotion后两部分大小极度不平衡的话
*会造成两部分大小不等，就会退化成O(n^2)
*造成退化成O(n^2)的主要原因就是两部分极度不平衡
*/
int __partition2(vector<int> &nums, int l, int r)
{
	// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	swap(nums[l], nums[rand() % (r - l + 1) + l]);
	int v = nums[l];
	//[l,..,i)<=v (j,...,r]>=v
	int i = l + 1, j = r;
	while (true)
	{
		while (i < r && nums[i] < v) i++; //nums[i] < v而不是 nums[i] <= v这样相等的元素可分到两边不会使两部分不平衡
		while (j > l && nums[j] > v) j--;//nums[j] > v 而不是 nums[j] >= v
		if (i > j) break;
		swap(nums[i], nums[j]);
		i++; j--;
	}
	swap(nums[l], nums[j]);
	return j;
}
void __quickSort2(vector<int> &nums, int l, int r)
{
	if (l >= r) return;
	// 对于小规模数组, 使用插入排序进行优化
	if (r - l <= 15) {
		instertSort(nums, l, r);
		return;
	}
	int p = __partition2(nums, l, r);
	__quickSort2(nums, l, p - 1);
	__quickSort2(nums, p + 1, r);

	return;
}
void quickSort2(vector<int> &nums)
{
	if (nums.empty())
		return;
	int n = nums.size();
	srand(time(NULL));
	__quickSort2(nums, 0, n - 1);

	return;
}
int main()
{
	int n = 1000;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, n);
	//mergeSortBU(vec);
	quickSort1(vec);
	SortTestHelper::testSort("quickSort2", quickSort2, vec);
	//SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}
