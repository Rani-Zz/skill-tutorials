#include <iostream>

using namespace std; 
class UnionFind2{
	private:
		int* parent;
		int count;
	public:
		UnionFind2(int n)
		{
			parent = new int[n];
			count = 0;
			
			for(int i = 0;i<n;i++)
			{
				parent[i] = i;//刚开始都指向自己 
			}
		}
		~UnionFind2()
		{
			delete[] parent;	
		} 
		
		// 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
		int find(int p)
		{
			while(p!=parent[p])
			p = parent[p];
			
			return p;
		}
		
		bool isConnected(int p,int q)
		{
			return find(p)==find(q);
		}
		
		// 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionElements(int p,int q)
        {
        	int pRoot = find(p);
        	int qRoot = find(q);
        	
        	if(pRoot==qRoot)
        	return;
        	
        	parent[pRoot] = qRoot;
		}
};

int main() {
	UnionFind2 uf = UnionFind2(10);
	int res = uf.find(1);
	cout<<res<<endl;
	return 0;
}
