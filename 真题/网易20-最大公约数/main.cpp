/**
*输入两个数a,b
求最大公约数
*/
#include<iostream>
#include<string>
using namespace std;
long long gcd(long long a, long long b)
{
	return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
	string s;
	while (cin >> s) {
		long long b;
		cin >> b;
		long long a = 0;
		for (int i = 1; i < s.size(); i++)
		{
			a = (a * 10 + s[i] - '0') % b;
		}
		cout << gcd(a, b) << endl;
	}
	system("pause");
	return 0;
}