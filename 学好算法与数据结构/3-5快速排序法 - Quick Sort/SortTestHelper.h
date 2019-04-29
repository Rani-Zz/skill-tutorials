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


	// 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
	template<typename T>
	void testSort(const string &sortName, void(*sort)(vector<T>&), vector<T> arr) {

		clock_t startTime = clock();
		sort(arr);
		clock_t endTime = clock();
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		//assert(isSorted(arr, n));

		return;
	}
}