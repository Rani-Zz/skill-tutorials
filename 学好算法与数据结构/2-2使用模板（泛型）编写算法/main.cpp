#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <typename T>
void selectSort(vector<T> &vec)
{
	if (vec.empty())
		return;
	for (int i = 0; i < vec.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < vec[min])
				min = j;
		}
		swap(vec[i], vec[min]);
	}
	return;
}
int main()
{
	vector<int> vec = { 10,9,8,7,6,5,4,3,2,1 };
	selectSort(vec);
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	vector <double> b = { 4.4,3.3,2.2,1.1 };
	selectSort(b);
	for (auto i : b)
		cout << i << " ";
	cout << endl;

	// 测试模板函数，传入字符串数组
	vector<string> c = { "D","C","B","A" };
	selectSort(c);
	for (auto i : c)
		cout<< i << " ";
	cout << endl;



	system("pause");
    return 0;
}