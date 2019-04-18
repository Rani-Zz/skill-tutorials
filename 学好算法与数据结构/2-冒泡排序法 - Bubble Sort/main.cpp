#include "SortTestHelper.h"
#include<iostream>
#include<vector>

using namespace std;

template <typename T>
void bubbleSort(vector<T> &vec)
{
	if(vec.empty())
	return;
	
	int n = vec.size();
	for(int i = n-1;i>=0;i--)
	{
		bool flag = false;
		for(int j = 1;j<=i;j++)
		{
			if(vec[j-1]>vec[j])
			{
				swap(vec[j],vec[j-1]);
				flag = true;
			}
		}
		if(!flag)
		return;
	}
	
	return;
	
}
int main()
{
	vector<int> vec = {10,9,8,7,6,5,4,3};
	bubbleSort(vec);
	for(auto i:vec)
	{
		cout<<i <<" ";
	}
	cout<<endl;
	system("pause");
    return 0;
}
