#include "SortTestHelper.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/**
*存在重复元素的优势很大
*/
void __quickSort3ways(vector<int> &nums, int l, int r)
{
	if (l >= r)
		return;
	// 对于小规模数组, 使用插入排序进行优化
	if (r - l <= 15) {
		instertSort(nums, l, r);
		return;
	}

	swap(nums[l], nums[rand() % (r - l + 1) + l]);
	int v = nums[l];
	//[l+1,...,lt]  [lt+1,...,i) [gt,..,r]
	int lt = l;//[l+1,..,lt]<v
	int gt = r + 1;//[gt,...,r]>v
	int i = l + 1;//[lt+1,..,i)==v
	while (i < gt)
	{
		if (nums[i] < v)
		{
			swap(nums[i], nums[lt + 1]);
			lt++; i++;
		}
		else if (nums[i] > v)
		{
			swap(nums[i], nums[gt-1]);
			gt--;
		}
		else
			i++;
	}
	swap(nums[l], nums[lt]);
	__quickSort3ways(nums, l, lt - 1);//<v部分
	__quickSort3ways(nums, gt, r);//>v部分

}
void quickSort3ways(vector<int> &nums)
{
	if (nums.empty())
		return;
	srand(time(NULL));
	int n = nums.size();
	__quickSort3ways(nums, 0, n - 1);

	return;
}
int main()
{
	int n = 1000;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, n);
	//mergeSortBU(vec);
	quickSort1(vec);
	SortTestHelper::testSort("quickSort3ways", quickSort3ways, vec);
	//SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}
