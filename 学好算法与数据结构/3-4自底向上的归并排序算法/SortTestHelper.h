#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<cassert>
using namespace std;

namespace SortTestHelper {

	vector<int> generateRandomArray(int n, int rangL, int rangR)
	{
		assert(rangL <= rangR);
		vector<int> vec(n, 0);
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			vec[i] = rand() % (rangR - rangL + 1) + rangL;
		}
		return vec;
	}
	
	template <typename T>
	void printArray(vector<T> vec)
	{
		for (auto i : vec)
			cout << i << " ";
		cout << endl;

		return;
	}
}