#include "SortTestHelper.h"
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
	int n = 2000;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, 1000);
	selectSort(vec);
	SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}