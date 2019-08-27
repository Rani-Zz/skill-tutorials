#include<iostream>
#include<vector>
using namespace std;
void build_tree(vector<int> arr,vector<int> &tree,int node,int start,int end)
{
	if(start==end)
	{
		tree[node] = arr[start];
		return;
	}
	int mid = start+(end-start)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	
	build_tree(arr,tree,left_node,start,mid);
	build_tree(arr,tree,right_node,mid+1,end);
	
	//tree[node]保存结点信息
	tree[node] = tree[left_node]+tree[right_node];
	return; 
}
void update_tree(vector<int>& arr,vector<int>& tree,int node,int start,int end,int index,int val)
{
	if(start==end)
	{
		arr[index]=val;
		tree[node] = val;
		return;
	}
	
	int mid = start+(end-start)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	if(index>=start&&index<=mid)
	{
		update_tree(arr,tree,left_node,start,mid,index,val);
	}else
	{
		update_tree(arr,tree,right_node,mid+1,end,index,val); 
	}
	tree[node] = tree[left_node]+tree[right_node];
	return;
}

//求arr中[L...R]间的和 
int query_tree(vector<int> arr,vector<int> tree,int node,int start,int end,int L,int R)
{
	if(R<start||L>end) 
	{
		return 0;
	}
	if(start>=L&&end<=R)
	{
		return tree[node];
	}
	
	if(start==end)
	{
		return tree[node];
	}
	int mid = start+(end-start)/2;
	int left_node = 2*node+1;
	int right_node = 2*node+2;
	int sum_left = query_tree(arr,tree,left_node,start,mid,L,R);
	int sum_right = query_tree(arr,tree,right_node,mid+1,end,L,R);
	 
	return sum_left+sum_right; 
} 

int main()
{
	vector<int> arr = {1,3,5,7,9,11};
	vector<int> tree(4*arr.size(),-1);
	int n = arr.size();
	build_tree(arr,tree,0,0,n-1);
	update_tree(arr,tree,0,0,n-1,4,6);
	for(auto i:tree)
	{
		cout<<i<<endl; 
	}
	
	int res = query_tree(arr,tree,0,0,n-1,2,5); 
	cout<<"[2,5]:"<<res<<endl;
	return 0;
}