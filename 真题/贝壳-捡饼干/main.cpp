#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getMax(vector<vector<int>> w, int n)
{
	if (w.empty())
		return 0;
	for (int j = 1; j < n; j++)
		w[0][j] += w[0][j - 1];
	for (int i = 1; i < n; i++)
		w[i][0] += w[i - 1][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			w[i][j] += max(w[i - 1][j], w[i][j - 1]);
	}
	return w[n - 1][n - 1];
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> w(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> w[i][j];
		}
		int res = getMax(w, n);
		cout << res << endl;
	}
	return 0;
}
/**
问题描述：
小明在一个 n*n 的网格图上，每个格点(i,j)都有 w[i][j]个饼干。小明现在在（1，1），他要去（n,n）,他只
能往右上走{即在（i，j）,能走到(i+1,j)或（i,j+1）},并且会捡他经过的饼干。问小明走到（n,n）点时最多
拿多少个饼干。
输入描述：
输入若干行，第一行有一个整数 n。接下来有 n 行，每行有 n 个整数，第 i 行第 j 个整数表示 w[i][j]
输出描述：
输出一行，表示答案
输入样例：
3
1 1 0
0 1 0
0 1 1
输出样例：
5
样例解释：
数据范围
小数据 n<=10
大数据 n<=1000
*/