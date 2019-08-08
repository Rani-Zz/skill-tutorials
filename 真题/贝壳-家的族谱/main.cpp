#include<iostream>
#include<unordered_map>
using namespace std;
bool find(unordered_map<int, int> map, int a, int b)
{
	int t = a;
	while (t != -1)
	{
		auto it = map.find(t);
		if (it != map.end())
		{
			t = it->second;
			if (b == t)
			{
				return true;
			}
		}
		else
			break;
	}
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		unordered_map<int, int> map;
		for (int i = 0; i < n; i++)
		{
			int s, p;
			cin >> s >> p;
			auto it = map.find(s);
			if (it!=map.end())
			{
				swap(s, p);
			}
			map[s] = p;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			int res = 0;
			res = find(map, a, b) ? 2 : res;
			
			swap(a, b);
			res = find(map, a, b) ? 1 : res;

			cout << res << endl;
		}
	}
	return 0;
}
/**
小明和小红是亲兄妹，他俩一起翻了翻他们家的族谱，发现他们家非常庞大，有非常多的名字在族谱里面。族谱中会写清楚每一个人的父亲是谁，当然每个人都只会有一个父亲。

对于祖先的定义，我们在这儿举个例子：族谱里面会写小王的父亲是小丁，小丁的父亲是小东，那么实际上小东就是小王的爷爷，也是小王的祖先。

小明很聪明，小明理了理他们的家庭关系，很快就弄清楚了，知道了族谱中每一个人的祖先关系。

但是小红却依旧困惑，于是问了很多问题，希望你能够解答。

小红的问题是，请问A是B的祖先关系是什么？究竟A是不是B的祖先，或者说B是A的祖先，亦或者B和A不存在祖先关系呢。
输出
对于每一个询问。

输出1表示A是B的祖先，输出2表示B是A的祖先，都不是输出0
样例输入
10
1 -1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
2 10
5
1 2
2 3
2 4
2 5
2 10
样例输出
1
0
0
0
2
*/