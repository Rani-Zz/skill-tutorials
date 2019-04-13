#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int minlen(string &s)
	{
		int i = 0;
		while (s.size()&&i < s.size() - 1)
		{
			if ((s[i] == '0'&&s[i + 1] == '1') || s[i] == '1'&&s[i + 1] == '0')
			{
				s.erase(i, 2);
				i = 0;
			}
			else
				i++;
		}
		return s.size();
	}
};
int main()
{
	Solution s;
	string str;
	while (cin >> str)
	{
		int len = s.minlen(str);
		cout << len << endl;
	}
	return 0;
}