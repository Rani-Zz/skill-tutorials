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
		//构造函数 
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
		
		// 查找过程, 查找元素p所对应的集合编号 O(1) 
		int find(int p)
		{
			return id[p];
		}
		
		bool isConnected(int p,int q)
		{
			return find(p)==find(q);
		} 
		
		//合并元素 
		// O(n) 复杂度
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
class UnionFind3{
	private:
		int* parent;
		int* sz;//sz[i]表示以i为根的结点个数 
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
// 测试第一版本的并查集, 测试元素个数为n
    void testUF1( int n ){

        srand( time(NULL) );
        UnionFind1 uf = UnionFind1(n);

        time_t startTime = clock();

        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for( int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for(int i = 0 ; i < n ; i ++ ){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    // 测试第二版本的并查集, 测试元素个数为n, 测试逻辑和之前是完全一样的
    // 思考一下: 这样的冗余代码如何消除?
    // 由于这个课程不是设计模式课程, 在这里就不过多引入相关的问题讲解了。留作给大家的思考题:)
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

    // 测试第三版本的并查集, 测试元素个数为n
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

    // 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
    // 总体测试过程的算法复杂度是O(n^2)的
    testUF1(n);

    // 对于UF2来说, 其时间性能是O(n*h)的, h为并查集表达的树的最大高度
    // 这里严格来讲, h和logn没有关系, 不过大家可以简单这么理解
    // 我们后续内容会对h进行优化, 总体而言, 这个h是远小于n的
    // 所以我们实现的UF2测试结果远远好于UF1, n越大越明显:)
    testUF2(n);

    // 对于UF3来说, 其时间性能依然是O(n*h)的, h为并查集表达的树的最大高度
    // 但由于UF3能更高概率的保证树的平衡, 所以性能更优
    testUF3(n);
	return 0;
}
