#include<iostream>
#include<vector>
using namespace std;

void selectSort(vector<int> &vec)
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
	system("pause");
    return 0;
}