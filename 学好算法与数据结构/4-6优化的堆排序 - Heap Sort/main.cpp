#include <iostream>
#include<vector>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void __shiftdown(vector<int>& nums,int n,int k)
{
	while(k*2+1<n)
	{
		int j = k*2+1;
		if(j+1<n&&nums[j]<nums[j+1])
		{
			j++;
		}
		
		if(nums[k]>=nums[j])
		break;
		
		swap(nums[k],nums[j]);
		
		k = j;
	}
	return;
}
void headSort(vector<int>& nums)
{
	if(nums.empty())
	return;
	
	int n = nums.size();
	for(int i = (n-1-1)/2;i>=0;i--)
	{
		__shiftdown(nums,n,i);
	}
	
	for(int i = n-1;i>0;i--)
	{
		swap(nums[i],nums[0]);
		__shiftdown(nums,i,0);
	}
}
int main() {
	

	
	vector<int> nums2 = {9,3,4,2,5,73,2,83};
	headSort(nums2);
    for(auto i:nums2)
	{
		cout<<i<<" "; 
	}
	
	return 0;
}
