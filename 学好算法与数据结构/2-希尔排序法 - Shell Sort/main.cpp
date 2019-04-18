#include "SortTestHelper.h"
#include<iostream>
#include<vector>

using namespace std;
void shellSort(vector<T> &vec)
{
	int h = 1;
	int n = vec.size();

	// 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
	while (h < n / 3)
	{
		h = 3 * h + 1;
	}

	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			T temp = vec[i];
			int j = i;
			while (j >= h && vec[j-h] > temp)
			{
				vec[j] = vec[j - h];
				j -= h;
			}
			vec[j] = temp;
		}
		h /= 3;
	}
	return;
}
int main()
{
	int n = 10;
	vector<int> vec = SortTestHelper::generateRandomArray(n, 0, 10);
	shellSort(vec);
	SortTestHelper::printArray(vec);
	system("pause");
    return 0;
}