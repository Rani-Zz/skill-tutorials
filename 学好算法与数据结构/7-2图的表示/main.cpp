#include <iostream>
#include<vector>
#include<cassert> 

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//邻接矩阵 
class DenseGraph{
	private:
		int n,m;//n 结点个数 m 边个数
		bool isdirected;//是否有向
		vector<vector<int>> g; 
	public:
		DenseGraph(int n,int m,vector<vector<int>> g):n(n),m(m),g(g){
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
};
int main() {

	return 0;
}
