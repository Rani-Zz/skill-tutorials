#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 
using namespace std; 
//广度遍历求无权图的最短路径 
template <typename Graph>
class ShortestPath{
	private:
		Graph &G;
		int s;
		bool* visited;//记录dfs的过程中节点是否被访问
		int* ord; //记录路径中节点的次序。ord[i]表示i节点在路径中的次序。
		int from; //记录路径, from[i]表示查找的路径上i的上一个节点
	public:
		 // 构造函数, 寻找无权图graph从s点到其他点的最短路径
		 ShortestPath(Graph &graph,int s):G(graph),s(s)
		 {
		 	visited = new bool[G.V()];
		 	from = new int[G.V()];
		 	ord = new int[G.V()];
		 	
		 	for(int i = 0;i<G.V();i++)
		 	{
		 		visited[i] = false;
		 		from[i] = -1;
		 		ord[i] = -1;
			 }
			 
			 queue<int> q;
			 q.push(s);
			 visited[s] = true;
			 ord[s] = 0;
			 
			 while(!q.empty())
			 {
			 	int v = q.front();
			 	q.pop();
			 	
			 	typename Graph::adjIterator adj(G,v);
			 	for(int i = adj.begin();i!=adj.end();i=adj.next())
			 	{
			 		if(!visited[i])
					 {
					 	q.push(i);
					 	visited[i] = true;
					 	from[i] = v;
					 	ord[i] = ord[v]+1;
					  } 
				}
			 	
			 } 
		 } 
		 // 析构函数
		 ~ShortestPath()
		 {
		 	delete[] visited;
		 	delete[] from;
		 	delete[] ord;
		 }
		 // 查询从s点到w点是否有路径
		 bool isConnexted(int w)
		 {
		 	assert(w>=0&&w<G.V());
		 	return visited[w];
		 }
		 // 查询从s点到w点的路径, 存放在vec中
		 void path(int w,vector<int>& vec)
		 {
		 	assert(w>=0&&w<G.V());
		 	stack<int> s;
		 	
		 	int p = w;
		 	while(from[p]!=-1)
		 	{
		 		s.push(from[p]);
		 		p = from[p];
			}
			
			while(!s.empty())
			{
				vec.push_back(s.top());
				s.pop();
			}
		 }
		 // 打印出从s点到w点的路径
		 void printPath(int w)
		 {
		 	assert(w>=0&&w<G.V());
		 	vector<int> vec;
		 	path(w,vec);
			for(int i = 0;i<vec.size();i++)
			{
				cout<<vec[i];
				if(i==vec.size()-1)
				cout<<endl;
				else 
				cout<<"->"; 
			 } 
		 }
		 // 查看从s点到w点的最短路径长度
		 int length(int w)
		 {
		 	assert(w>=0&&w<G.V());
		 	return ord[w];		 	
		 }
	
};
int main() {
 
	return 0;
}
