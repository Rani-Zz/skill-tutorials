#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/**
*求任意数组第k小（大）的值
*/
// partition 过程, 和快排的partition一样
// 思考: 双路快排和三路快排的思想能不能用在selection算法中? :)
int __partitionSelection(vector<int> &nums, int l, int r)
{
	
	swap(nums[l], nums[rand() % (r - l + 1) + l]);
	int v = nums[l];
	int j = l; //[l+1...j] < p ; [j+1..i) > p
	for (int i = l + 1; i <= r; i++)
	{
		if (nums[i] < v)
			swap(nums[i], nums[j++]);
	}
	swap(nums[l], nums[j]);
	return j;
}
//求出arr[l...r]范围里第k小的数
int __selection(vector<int> &nums, int l, int r, int k)
{
	if (l == r)
		return nums[l];
	int p = __partitionSelection(nums, l, r);
	if (p == k)
		return nums[p];
	else if (p > k)
		return __selection(nums, l, p - 1,k);
	else
		return __selection(nums, p + 1, r,k);
}
int selection(vector<int> &nums, int k)
{
	if (nums.empty() || k < 1)
		return -1;
	int n = nums.size();
	srand(time(NULL));
	return __selection(nums, 0, n - 1, k);
}
int main()
{
	int n = 10;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, n);
	vector<int> nums = { 9,8,7,6,5,4,3,2,1 };
	int res = selection(nums,4);
	cout << res << endl;
	//mergeSortBU(vec);
	//SortTestHelper::testSort("quickSort3ways", quickSort3ways, vec);
	//SortTestHelper::printArray(vec);
	system("pause");
    return 0;