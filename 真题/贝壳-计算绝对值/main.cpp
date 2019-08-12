/**
100%
计算绝对值
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
给出n个正整数，要求找出相邻两个数字中差的绝对值最小的一对数字，如果有差的绝对值相同的，则输出最前面的一对数。

2<n<=100，正整数都在10^16范围内

输入
输入包含2行，第一行为n，第二行是n个用空格分隔的正整数。

输出
输出包含一行两个正整数，要求按照原来的顺序输出


样例输入
9
1 3 4 7 2 6 5 12 32
样例输出
3 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> diffMin(vector<long long> nums, int n)
{
long long diff = (nums[1]>nums[0])?(nums[1]-nums[0]):(nums[0]-nums[1]);
vector<long long> res;
res.push_back(nums[0]);
res.push_back(nums[1]);
for (int i = 2; i<n; i++)
{
long long tmp = (nums[i]>nums[i-1])?(nums[i]-nums[i-1]):(nums[i-1]-nums[i]);
if (tmp<diff)
{
res.pop_back();
res.pop_back();
res.push_back(nums[i - 1]);
res.push_back(nums[i]);
diff = tmp;
}
}
return res;

}
int main()
{
int n;
while (cin >> n)
{
vector<long long> nums(n, 0);
for (int i = 0; i<n; i++)
{
cin >> nums[i];
}
vector<long long> res = diffMin(nums, n);
for (auto i : res)
cout << i << " ";
cout << endl;
}
return 0;
}