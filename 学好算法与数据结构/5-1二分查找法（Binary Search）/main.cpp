#include <iostream>
#include<vector>
using namespace std; 
//�ǵݹ� 
int BinarySearch(vector<int> nums,int target)
{
	if(nums.empty())
	return -1;
	
	// ��[l...r]֮�в���target
	int l = 0,r = nums.size()-1;
	while(l<=r)
	{
		//int mid = (l+r)/2;
		// ��ֹ��������µ����������ʹ��������߼����mid
		int mid = l+(r-l)/2;
		if(nums[mid]==target)
		return mid;
		
		if(nums[mid]>target)
		{
			r = mid-1;
		}else
		{
			l = mid + 1;
		}
	}
	
	return -1;
}
//�ݹ�
//�ǵݹ��㷨����������΢������
int __BinarySearch2(vector<int> nums,int l,int r,int target)
{
	if(l>r) return -1;
	int mid = l+(r-l)/2;
	if(nums[mid]==target)
	return mid;
	
	if(nums[mid]>target)
		return __BinarySearch2(nums,l,mid-1,target);
	else
		return __BinarySearch2(nums,mid+1,r,target);
	
 } 
 int BinarySearch2(vector<int> nums,int target)
 {
 	if(nums.empty())
 	return -1;
 	
 	int n = nums.size();
 	int res = __BinarySearch2(nums,0,n-1,target);
 }
int main() {
    vector<int> nums1 = {9,3,4,2,5,73,2,83};
	int res = BinarySearch2(nums1,2);
	cout<<res<<endl;
	
	return 0;
}
