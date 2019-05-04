#include <iostream>
#include<vector>
#include<ctime>
#include "heap.h"
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void indexheapSort(vector<int>& nums)
{
	if(nums.empty())
	return;
	
	int n = nums.size();
	IndexMaxHeap<int> indexmaxheap = IndexMaxHeap<int>(n);
	
	for(int i = 0;i<n;i++)
	{
		indexmaxheap.insert(nums[i],i);
	}
	
	for(int i = n-1;i>=0;i--)
	{
		nums[i] = indexmaxheap.extractMax();
	}
}
int main() {

	
	vector<int> nums4 = {9,3,4,2,5,73,2,83};
	indexheapSort(nums4);
    for(auto i:nums4)
	{
		cout<<i<<" "; 
	}
	cout<<endl;
	
	return 0;
}
