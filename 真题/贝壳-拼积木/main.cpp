#include<iostream>
#include<deque>
#include<map>
using namespace std;
bool connect(multimap<int, int> map)
{
	auto it = map.begin();
	deque<int> d;
	d.push_back(it->first);
	d.push_back(it->second);
	it++;
	while (it != map.end())
	{
		if (it->first == d.back())
		{
			d.pop_back();
			d.push_back(it->second);
		}
		else if (it->first == d.front())
		{
			d.pop_front();
			d.push_front(it->second);
		}
		else if (it->second == d.back())
		{
			d.pop_back();
			d.push_back(it->first);
		}
		else if (it->second == d.front())
		{
			d.pop_front();
			d.push_front(it->first);
		}
		else
			return false;
		it++;
	}
	return true;
}
int main()
{
	int t;

	while (cin >> t)
	{
		while (t--)
		{
			int n;
			cin >> n;
			multimap<int, int> map;
			for (int i = 0; i < n; i++)
			{
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				if (tmp1 < tmp2)
					map.insert(make_pair(tmp1, tmp2));
				else
					map.insert(make_pair(tmp2, tmp1));

			}
			bool res = connect(map);
			if (res)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;

		}
		
	}
	return 0;
}
/**
问题描述：
一天，小明买了许多积木回家，他想把这些积木拼接在一起。每块积木有两个接口，每个接口我们用
一个数字标记，规定只有当两块积木有相同数字标记的接口时，这两块积木才可以通过该接口拼接在一起。
举例，有两块积木，接口数字分别为 1，2 和 3，4，那么这两块积木无法拼接；若两块积木接口数字分别
为 1，2 和 2，3，那么这两块积木可以通过由数字 2 标记的接口拼接在一起。现在小明知道所有积木的数
量和每块积木接口的数字标记，你能告诉他他可以将所有积木拼接成一个整体么？
输入描述：
第一行一个整数 t，表示测试数组组数 ；
接下来在每组测试数据中：
第一行一个整数 n，表示积木的数量 ，
下面 n 行每行 2 个整数 x，y，表示其中一块积木的两个接口的数字标记； ；
输出描述：
对于每组测试数据，输出”YES”，表示该组数据中的所有积木可以拼接成一个整体，”NO”表示不行。
（注意输出不包括引号）
输入样例：
23
1 2
2 3
4 5
6
1 2
2 3
3 5
4 5
4 6
5 1
输出样例：
NO
YES
样例解释：
在第一组测试数据中，有 3 块积木，显然前两块是可以拼接在一起的，但是第 3 块无论如何也无法和
前两块拼接，所以输出 NO；第二组数据中我们可以这样拼接：5-1-1-2-2-3-3-5-5-4-4-6，因此输出 YES。
*/
