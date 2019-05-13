#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 
using namespace std; 
//��ȱ�������Ȩͼ�����·�� 
template <typename Graph>
class ShortestPath{
	private:
		Graph &G;
		int s;
		bool* visited;//��¼dfs�Ĺ����нڵ��Ƿ񱻷���
		int* ord; //��¼·���нڵ�Ĵ���ord[i]��ʾi�ڵ���·���еĴ���
		int from; //��¼·��, from[i]��ʾ���ҵ�·����i����һ���ڵ�
	public:
		 // ���캯��, Ѱ����Ȩͼgraph��s�㵽����������·��
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
		 // ��������
		 ~ShortestPath()
		 {
		 	delete[] visited;
		 	delete[] from;
		 	delete[] ord;
		 }
		 // ��ѯ��s�㵽w���Ƿ���·��
		 bool isConnexted(int w)
		 {
		 	assert(w>=0&&w<G.V());
		 	return visited[w];
		 }
		 // ��ѯ��s�㵽w���·��, �����vec��
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
		 // ��ӡ����s�㵽w���·��
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
		 // �鿴��s�㵽w������·������
		 int length(int w)
		 {
		 	assert(w>=0&&w<G.V());
		 	return ord[w];		 	
		 }
	
};
int main() {
 
	return 0;
}
