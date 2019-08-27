/**
要用二分 O(nlongn)
动态规划 82% 会超时 O(n^2)
月光宝盒的密码
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
小希偶然得到了传说中的月光宝盒,然而打开月光宝盒需要一串密码。虽然小希并不知道密码具体是什么，
但是月光宝盒的说明书上有着一个长度为 n (2 <= N <= 50000)的序列 a (-10^9 <= a[i] <= 10^9)的范围内。
下面写着一段话：密码是这个序列的最长的严格上升子序列的长度(严格上升子序列是指，子序列的元素是严格递增的，
例如: [5,1,6,2,4]的最长严格上升子序列为[1,2,4])，请你帮小希找到这个密码。


输入
第1行：1个数N，N为序列的长度(2<=N<=50000)

第2到 N+1行：每行1个数，对应序列的元素(-10^9 <= a[i] <= 10^9)

输出
一个正整数表示严格最长上升子序列的长度


样例输入
8
5
1
6
8
2
4
5
10
样例输出
5
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longest(vector<int> nums, int n)
{
	if (n<2)
		return n;
	vector<int> dp;
	dp.push_back(nums[0]);
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > dp.back())
			dp.push_back(nums[i]);
		else
		{
			dp[lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin()] = nums[i];
		}
	}
	return dp.size();
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n, 0);
		for (int i = 0; i<n; i++)
			cin >> nums[i];
		int res = longest(nums, n);
		cout << res << endl;
	}
	return 0;
}
