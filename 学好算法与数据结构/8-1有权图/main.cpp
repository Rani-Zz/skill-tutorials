#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 
//#include "heap.h"
//#include "bst.h"
//#incldue "UnionFind1.h"
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//带权边
template <typename Weight>
class Edge{
	private:
		int a;// 边的两个端点
		int b;
		Weight weight; //权值 
	public:
		// 构造函数
		Edge(int v,int w,Weight weight):a(v),b(w), weight(weight){
		}
		
		//析构函数 
		~Edge(){
		}
		
		// 返回第一个顶点
		int v(){
			return a;
		} 
		
		// 返回第二个顶点 
		int w(){
			return b;
		}
		
		// 给定一个顶点, 返回另一个顶点
		int other(int v)
		{
			return v==a?b:a;
		}
		
		// 返回权值
		Weight wt(){
			return weight;
		}
		// 输出边的信息
		friend ostream& operator<<(ostream& os,const Edge& e)
		{
			os<<e.a<<"-"<<e.b<<":"<<e.weight;
			return os;
		}
		// 边的大小比较, 是对边的权值的大小比较
		bool operator<(Edge<Weight>& e)
		{
			return weight<e.wt();
		}
		bool operator<=(Edge<Weight>& e)
		{
			return weight<=e.wt();
		}
		bool operator>(Edge<Weight>& e)
		{
			return weight>e.wt();
		}
		bool operator>=(Edge<Weight>& e)
		{
			return weight>=e.wt();
		}
		bool operator==(Edge<Weight>& e)
		{
			return weight==e.wt();
		}
}; 
//邻接矩阵 
template <typename Weight>
class DenseGraph{
	private:
		int n,m;//n 结点个数 m 边个数
		bool isdirected;//是否有向
		vector<vector<Edge<Weight> *>> g; 
	public:
		DenseGraph(int n,bool isdirected):n(n),m(0),isdirected(isdirected),g(vector<vector<Edge<Weight>*>>(n,vector<Edge<Weight>*>(n,NULL))){
		}
		
		~DenseGraph(){
		}
		
		//返回结点个数 
		int V()
		{
			return n;
		}
		//返回边个数 
		int E()
		{
			return m;
		}
		//返回v,w之间是否有边 
		bool hasEdge(int v,int w)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&w<n);
			
			return g[v][w]!=NULL;
			 
		} 
		//在v,w间增加一条边 
	    void addEdge(int v,int w,Weight weight)
	    {
	    	 assert(v>=0&&v<n);
			assert(v>=0&&w<n);
			if(hasEdge(v,w))
			 {
			 	delete g[v][w];
			 	m--;
			}  
			
			g[v][w] = new Edge<Weight>(v,w,weight);
			if(isdirected) 
			{
				g[w][v] = new Edge<Weight>(w,v,weight);;
			}
			
			m++;
			return;
		}
		
		//显示图的信息 
		void show()
		{
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<n;j++)
				{
					if(g[i][j])
					{
						cout<<g[i][j]->wt()<<" ";
					}else
					 	cout<<"NULL";
				}
				
				cout<<endl;
			}
		}
		
		class adjIterator{
			private:
				DenseGraph &G;
				int v;
				int index;
			public:
				adjIterator(DenseGraph graph,int v):G(graph),v(v),index(-1){
				}
				
				~adjIterator(){
				}
				
				Edge<Weight>* begin()
				{
					index = -1;
					return next();
				}
				
				Edge<Weight>* next()
				{
					for(index+=1;index<G.V();index++)
					{
						if(G.g[v][index])
						   return G.g[v][index];
					}
					
					return NULL;
				}
				
				bool end()
				{
					return index>=G.V();
				}
		};
};

//领接表 
//稀疏图 
template <typename Weight> 
class SparseGraph{
	private:
		int n,m;//n结点个数 m 边个数
		bool isdirected;//是否有向
		vector<vector< Edge<Weight>* >> g;
	public:
		SparseGraph(int n,bool isdirected):n(n),m(0),isdirected(isdirected),g(vector<vector< Edge<Weight>* >>(n, vector<Edge<Weight>*>())){
		}	
		~SparseGraph(){
			for(int i = 0;i<n;i++)
			{
				for(int j = 0;j<g[i].size();j++)
				{
					delete g[i][j];
				}
			 } 
		}
		
		//返回结点个数 
		int V()
		{
			return n; 
		} 
		
		int E()
		{
			return m;
		 } 
		
		bool hasEdge(int v,int w)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&v<n);
			
			for(int i = 0;i<g[v].size();i++)
			{
				if(g[v][i]==w)
				return true;
			}
			
			return false;
		}
		
		void addEdge(int v,int w,Weight weight)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&v<n);
			

			// 注意, 由于在邻接表的情况, 查找是否有重边需要遍历整个链表
            // 我们的程序允许重边的出现	
            
			g[v].push_back(new Edge<Weight>(v,w,weight));
			if(v!=w&&isdirected)
				g[w].push_back(new Edge<Weight>(w,v,weight));
			
			m++;	
			return;
		}
		// 显示图的信息
		void show()
		{
			for(int i = 0;i<n;i++)
			{
				cout<<"vertex "<<i<<":\t";
				for(int j = 0;j<g[i].size();j++)
				{
					cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
				}
				cout<<endl; 
				
			}
		}
		class adjIterator{
			private:
				SparseGraph &G;
				int index;
				int v;
			public:
				adjIterator(SparseGraph graph,int v):G(graph),v(v),index(0){
				}
				
				~adjIterator(){
				}
				
				Edge<Weight>* begin(){
					index = 0;
					if(G.g[v].size())
					{
						return G.g[v][index];
					 } 
					 
					 return NULL;
				}
				
				Edge<Weight>* next()
				{
					index++;
					if(index<G.g[v].size())
					return G.g[v][index];
					
					return NULL;
				}
				
				bool end()
				{
					return index>=G.g[v].size();
				}
		};
	 
};



int main() {
	
    
	return 0;
}
