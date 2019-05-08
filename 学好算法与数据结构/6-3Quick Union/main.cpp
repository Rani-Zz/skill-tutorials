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
				parent[i] = i;//�տ�ʼ��ָ���Լ� 
			}
		}
		~UnionFind2()
		{
			delete[] parent;	
		} 
		
		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
        // O(h)���Ӷ�, hΪ���ĸ߶�
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
		
		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
        // O(h)���Ӷ�, hΪ���ĸ߶�
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
