#include<iostream>
#include<vector>
using namespace std;
int find_root(vector<int> parent,int x)
{
	int x_root = x;
	while(parent[x_root]!=-1)
	{
		x_root = parent[x_root];
	}
	return x_root;
 } 
 /**
 合并结点 
 */
int union_node(vector<int>& parent,vector<int>& rank,int x,int y)
{
	int x_root = find_root(parent,x);
	int y_root = find_root(parent,y);
	if(x_root==y_root)
	{
		return 0;
	}else
	{
		if(rank[x_root]>rank[y_root])
		{
			parent[y_root] = x_root;
		}else
		{
			parent[x_root] = y_root;
			rank[y_root]++;
		}
		
	} 
	
	return 1; 
	 
 } 
int main()
{
	int n = 6;
	vector<int> parent(n,-1);
	vector<int> rank(n,0);
	vector<vector<int>> edge = {{0,1},{1,2},{1,3},{2,4},{3,4},{2,5}};
	for(auto vec:edge)
	{
		if(union_node(parent,rank,vec[0],vec[1])==0)
		{
			cout<<"Cycle detected"<<endl;
			exit(0);
		}
	}
	return 0;
}