/**
//64%
举重大赛
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
举重大赛开始了，为了保证公平，要求比赛的双方体重较小值要大于等于较大值的90%，

那么对于这N个人最多能进行多少场比赛呢，任意两人之间最多进行一场比赛。

输入
第一行N，表示参赛人数（2<=N<=10^5）

第二行N个正整数表示体重（0<体重<=10^8）

输出
一个数，表示最多能进行的比赛场数


样例输入
5
1 1 1 1 1
样例输出
10
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int match(vector<long long> nums, int n)
{
	int res = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j<n&&nums[i] >= nums[j] * 0.9; j++)
			res++;
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<long long> nums(n,0);
		for (int i = 0; i<n; i++)
			cin >> nums[i];
		int res = match(nums, n);
		cout << res << endl;
	}
	return 0;
}