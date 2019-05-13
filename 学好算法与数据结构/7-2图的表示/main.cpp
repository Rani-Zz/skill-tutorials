#include <iostream>
#include<vector>
#include<cassert> 

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//�ڽӾ��� 
class DenseGraph{
	private:
		int n,m;//n ������ m �߸���
		bool isdirected;//�Ƿ�����
		vector<vector<int>> g; 
	public:
		DenseGraph(int n,int m,vector<vector<int>> g):n(n),m(m),g(g){
		}
		
		~DenseGraph(){
		}
		
		//���ؽ����� 
		int V()
		{
			return n;
		}
		//���ر߸��� 
		int E()
		{
			return m;
		}
		//����v,w֮���Ƿ��б� 
		bool hasEdge(int v,int w)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&w<n);
			
			return g[v][w];
			 
		} 
		//��v,w������һ���� 
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

//��ӱ� 
//ϡ��ͼ 
class SparseGraph{
	private:
		int n,m;//n������ m �߸���
		bool isdirected;//�Ƿ�����
		vector<vector<int>> g;
	public:
		SparseGraph(int n,int m,vector<vector<int>> g):n(n),m(m),g(g){
		}	
		~SparseGraph(){
		}
		
		//���ؽ����� 
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
	 
};

int main() {

	return 0;
}
