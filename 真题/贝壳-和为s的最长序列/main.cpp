#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest(vector<long long> nums, long long s)
{
	if (nums.empty())
		return -1;
	long long res = -1;
	long long l = 0, r = 0, tmp = nums[0];

	while (r<nums.size()-1)
	{
		if (tmp == s)
		{
			res = max(res, r - l + 1);
		}
		r++;
		tmp += nums[r];
		while (tmp > s&&l<r)
		{
			tmp -= nums[l];
			l++; 
		}
		
	}
	return res;
}
int main()
{
	long long  n, s;
	while (cin >> n >> s)
	{
		vector <long long> nums(n, 0);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		long long  res = longest(nums, s);
		cout << res << endl;
	}
	return 0;
}
/**
问题描述：
小 M 得到了一个长度为 n 的整数序列，但她不是很喜欢。她喜欢所有元素的和不超过 s 的序列。于是她决
定对这个序列进行一番修剪。小 M 可以将这个序列的开头和结尾的一部分数删去，然后使得剩下的数的和
不超过 s。同时她想使得剩下的序列尽可能长，请你帮忙计算最后她可以得到的序列最长是多少？
输入描述：
第一行包含两个整数n，s。1 ≤ n ≤ 105, −1018 ≤ 𝑠 ≤ 1018
第二行包含n个整数𝑎𝑖表示对应的序列。−109 ≤ 𝑎𝑖 ≤ 109
输出描述：
输出对应的答案，如果小 M 无法得到满足条件的序列，输出-1。
输入样例：
5 3
2 4 -2 1 1
输出样例：
3
样例解释：
可以将开头的 2 和结尾的 1 删去，得到序列 4 -2 1，和为 3，满足条件；不存在长度大于 3 的满足条件的
序列。
*/