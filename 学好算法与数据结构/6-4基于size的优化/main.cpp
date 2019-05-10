#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<cassert> 
//#include "heap.h"
//#include "bst.h"
//#incldue "UnionFind1.h"
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
class UnionFind3{
	private:
		int* parent;
		int* sz;//sz[i]��ʾ��iΪ���Ľ����� 
		int count;
	public:
		UnionFind3(int n)
		{
			parent = new int[n];
			sz = new int[n];
			count = n;
			for(int i =0;i<n;i++)
			{
				parent[i] = i;
				sz[i] = 1;
			}
		}
		
		~UnionFind3()
		{
			delete parent;
			delete sz;
		}
		
		int find(int p)
		{
			while(p!=parent[p])
			{
				p = parent[p];
			}
			
			return p;
		}
		
		bool isConnected(int p,int q)
		{
			return find(p)==find(q);
		}
		
		void unionElements(int p,int q)
		{
			int pRoot = find(p);
			int qRoot = find(q);
			if(pRoot==qRoot)
			return;
			
			if(sz[pRoot]<sz[qRoot])
			{
				parent[pRoot] = qRoot;
				sz[qRoot]+=sz[pRoot];
			}else
			{
				parent[qRoot] = pRoot;
				sz[pRoot]+=sz[qRoot];
			}
		}
};
// ���Ե�һ�汾�Ĳ��鼯, ����Ԫ�ظ���Ϊn
    void testUF1( int n ){

        srand( time(NULL) );
        UnionFind1 uf = UnionFind1(n);

        time_t startTime = clock();

        // ����n�β���, ÿ�����ѡ������Ԫ�ؽ��кϲ�����
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        // �ٽ���n�β���, ÿ�����ѡ������Ԫ��, ��ѯ�����Ƿ�ͬ��һ������
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        // ��ӡ�������2n�������ĺ�ʱ
        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // ���Եڶ��汾�Ĳ��鼯, ����Ԫ�ظ���Ϊn, �����߼���֮ǰ����ȫһ����
    // ˼��һ��: ��������������������?
    // ��������γ̲������ģʽ�γ�, ������Ͳ�����������ص����⽲���ˡ���������ҵ�˼����:)
    void testUF2( int n ){

        srand( time(NULL) );
        UnionFind2 uf = UnionFind2(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // ���Ե����汾�Ĳ��鼯, ����Ԫ�ظ���Ϊn
    void testUF3( int n ){

        srand( time(NULL) );
        UnionFind3 uf = UnionFind3(n);

        time_t startTime = clock();

        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

int main() {
	 int n = 10000;

    // ��ȻisConnectedֻ��ҪO(1)��ʱ��, ������union������ҪO(n)��ʱ��
    // ������Թ��̵��㷨���Ӷ���O(n^2)��
    testUF1(n);

    // ����UF2��˵, ��ʱ��������O(n*h)��, hΪ���鼯�����������߶�
    // �����ϸ�����, h��lognû�й�ϵ, ������ҿ��Լ���ô���
    // ���Ǻ������ݻ��h�����Ż�, �������, ���h��ԶС��n��
    // ��������ʵ�ֵ�UF2���Խ��ԶԶ����UF1, nԽ��Խ����:)
    testUF2(n);

    // ����UF3��˵, ��ʱ��������Ȼ��O(n*h)��, hΪ���鼯�����������߶�
    // ������UF3�ܸ��߸��ʵı�֤����ƽ��, �������ܸ���
    testUF3(n);
	return 0;
}
