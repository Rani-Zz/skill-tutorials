/**
题目：
假设有这样一个计算器，该计算器 只有两个按钮，按下第一个按钮能使显示数值-1，按下第二个按钮能使显示数值*2，当前显示数值为N,那么至少按多少次按钮能使显示数值编程M？

样例：
输入：
4 5
输出：
3
*/
#include<iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int count = 0;
		while (n != m)
		{
			if (n > m)
			{
				count += n - m;
				break;
			}
			if (m % 2) m++;
			else
				m /= 2;
			count++;
		}
		cout << count << endl;
	}
	
	return 0;
}