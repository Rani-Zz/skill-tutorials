#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 

using namespace std; 

//求图的连通分量 
template <typename Graph>
class Component{
	private:
		Graph &g;
		bool* visited;//记录dfs的过程中结点是否被访问 
		int count;//记录连通分量个数 
		int *id;//每个结点所对应的连通分量标记
		
		void dfs(int v)
		{
			visited[v] = true;
			id[v] = count;
			
			typename Graph::adjIterator adj(g,v);
			for(int i = adj.begin();i!=adj.end();i = adg.next())
			{
				if(!visited[i])
				{
					dif(i);
				}
			}
		}
	public:
		 // 构造函数, 求出无权图的联通分量
	    Component()
		{
			visited = new bool[g.V()];
			id = new int[g.V()];
			count = 0;
			
			for(int i = 0;i<g.V();i++)
			{
				visited[i] = false;
				id[i] = -1;
			}
			
			//求图的连通分量
			for(int i = 0;i<g.V();i++)
			{
				if(!visited[i])
				{
					dfs(i);
					count++;
				}
			} 
			
		 }
		 ~Component()
		 {
		 	delete[] visited;
		 	delete[] id;
		 }
		 
		 //返回连通分量个数
		 int getCount()
		 {
		 	return count;
		  } 
		  
		  //判断两个结点是否连通
		  bool isConnected(int v,int w)
		  {
		  	assert(v>=0&&v<=g.V());
		  	assert(w>=0&&w<=g.V());
		  	return id[v]==id[w];
		  } 
};
int main() {
    
	return 0;
}
