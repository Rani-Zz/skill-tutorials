
#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void insertSort(vector<T> &vec)
{
	if (vec.empty())
		return;
	for(int i = 1;i<vec.size();i++)
	{
		int tmp = vec[i];
		int j = i;
		while(j>0&&vec[j-1]>tmp)
		{
			vec[j] = vec[j-1];
			j--;
		}
		vec[j] = tmp;
	}
	return;
}
int main()
{
	vector<int> vec = {10,9,8,7,6,5,4,3};
	insertSort(vec);
	for(auto i:vec)
	{
		cout<<i <<" ";
	}
	cout<<endl;
	system("pause");
    return 0;
}
