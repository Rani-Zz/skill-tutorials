#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 
using namespace std; 
//Ѱ·�㷨 Ѱ��һ����㵽�������·��
template <typename Graph>;
class Path{
	private:
		Graph &G;
		bool* visited;
		int* from;
		int s;
		void dfs(int v)
		{
			visited[v] = true;
			
			typename Graph::adjIterator adj(G,v);
			for(int i = adj.begin();i!=adj.end();i = adj.next())
			{
				if(!visited[i])
				{
					from[i] = v;//��¼���ĸ��������� 
					dfs(i);
				}
			}
		}
	public:
		//Ѱ�ҽ��s����������·�� 
	    Path(Graph &graph,int s):G(graph),s(s)
		{
			visited = new bool[G.V()];
			from = new int[G.V()];
			for(int i = 0;i<G.V();i++)
			{
				visited[i] = false;
				from[i] = -1;
			}
			
			dfs(s);
			
		 } 
		~Path()
		{
			delete[] visited;
			delete[] from;
		}
		
		// ��ѯ��s�㵽w���Ƿ���·��
		bool isConnected(int w)
		{
			assert(w>=0&&w<G.V());
			return visited[w];
		 } 
		
		// ��ѯ��s�㵽w���·��, �����vec��
		void printPath(int w,vector<int>& vec)
		{
			assert(w>=0&&w<G.V());
			stack<int> s;

			int p =  w;
			while(p!=-1)
			{
				s.push(from[p]);
				p = from[p]; 
			} 
			
			vec.clear();
			while(!s.empty())
			{
				vec.push_back(s.top());
				s.pop();
			}
			
		}
		
		// ��ӡ����s�㵽w���·��
		void showPath(int w)
		{
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
};

int main() {
 
	return 0;
}
