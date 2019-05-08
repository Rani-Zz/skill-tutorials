#include <iostream>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class UnionFind1{
	private:
		int* id;
		int count;
	public:
		//���캯�� 
		UnionFind1(int n)
		{
			count = n;
			id = new int[n];
			for(int i = 0;i<n;i++)
			id[i] = i;
		}
		
		~UnionFind1()
		{
			delete[] id;
		} 
		
		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ�� O(1) 
		int find(int p)
		{
			return id[p];
		}
		
		bool isConnected(int p,int q)
		{
			return find(p)==find(q);
		} 
		
		//�ϲ�Ԫ�� 
		// O(n) ���Ӷ�
		void unionElements(int p,int q)
		{
			int pID = find(p);
			int qID = find(q);
			
			for(int i = 0;i<count;i++)
			{
				if(id[i]==pID)
				id[i] = qID; 
			} 
		}
};

int main() {
	UnionFind1 uf = UnionFind1(10);
	int res = uf.find(1);
	cout<<res<<endl;
	return 0;
}
