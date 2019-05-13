#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//邻接矩阵 
class DenseGraph{
	private:
		int n,m;//n 结点个数 m 边个数
		bool isdirected;//是否有向
		vector<vector<bool>> g; 
	public:
		DenseGraph(int n,bool isdirected):n(n),m(0),isdirected(isdirected),g(vector<vector<bool>>(n,vector<bool>(n,false))){
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
			
			return g[v][w];
			 
		} 
		//在v,w间增加一条边 
	    void addEdge(int v,int w)
	    {
	    	 assert(v>=0&&v<n);
			assert(v>=0&&w<n);
			if(hasEdge(v,w))
			return;
			
			g[v][w] = true;
			if(isdirected) 
			{
				g[w][v] = true;
			}
			
			m++;
			return;
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
				
				int begin()
				{
					index = -1;
					return next();
				}
				
				int next()
				{
					for(index+=1;index<G.V();index++)
					{
						if(G.g[v][index])
						   return index;
					}
					
					return -1;
				}
				
				bool end()
				{
					return index>=G.V();
				}
		};
};

//领接表 
//稀疏图 
class SparseGraph{
	private:
		int n,m;//n结点个数 m 边个数
		bool isdirected;//是否有向
		vector<vector<int>> g;
	public:
		SparseGraph(int n,bool isdirected):n(n),m(0),isdirected(isdirected),g(vector<vector<int>>(n, vector<int>())){
		}	
		~SparseGraph(){
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
		
		void addEdge(int v,int w)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&v<n);
			
			if(hasEdge(v,w))
				return;
				
			g[v].push_back(w);
			if(v!=w&&isdirected)
				g[w].push_back(v);
			
			m++;	
			return;
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
				
				int begin(){
					index = 0;
					if(G.g[v].size())
					{
						return G.g[v][index];
					 } 
					 
					 return -1;
				}
				
				int next()
				{
					index++;
					if(index<G.g[v].size())
					return G.g[v][index];
					
					return -1;
				}
				
				bool end()
				{
					return index>=G.g[v].size();
				}
		};
	 
};
int main() {
	 int N = 10;
    int M = 10;

    srand( time(NULL) );
    
    SparseGraph g1(N,false);
    for(int i = 0;i<N;i++)
    {
    	int a = rand()%N;
		int b = rand()%N; 
    	g1.addEdge(a,b);
	}
	
	 // O(E)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        SparseGraph::adjIterator adj( g1 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }
	
	
    
	return 0;
}
