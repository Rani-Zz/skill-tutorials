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
//��Ȩ��
template <typename Weight>
class Edge{
	private:
		int a;// �ߵ������˵�
		int b;
		Weight weight; //Ȩֵ 
	public:
		// ���캯��
		Edge(int v,int w,Weight weight):a(v),b(w), weight(weight){
		}
		
		//�������� 
		~Edge(){
		}
		
		// ���ص�һ������
		int v(){
			return a;
		} 
		
		// ���صڶ������� 
		int w(){
			return b;
		}
		
		// ����һ������, ������һ������
		int other(int v)
		{
			return v==a?b:a;
		}
		
		// ����Ȩֵ
		Weight wt(){
			return weight;
		}
		// ����ߵ���Ϣ
		friend ostream& operator<<(ostream& os,const Edge& e)
		{
			os<<e.a<<"-"<<e.b<<":"<<e.weight;
			return os;
		}
		// �ߵĴ�С�Ƚ�, �ǶԱߵ�Ȩֵ�Ĵ�С�Ƚ�
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
//�ڽӾ��� 
template <typename Weight>
class DenseGraph{
	private:
		int n,m;//n ������ m �߸���
		bool isdirected;//�Ƿ�����
		vector<vector<Edge<Weight> *>> g; 
	public:
		DenseGraph(int n,bool isdirected):n(n),m(0),isdirected(isdirected),g(vector<vector<Edge<Weight>*>>(n,vector<Edge<Weight>*>(n,NULL))){
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
			
			return g[v][w]!=NULL;
			 
		} 
		//��v,w������һ���� 
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
		
		//��ʾͼ����Ϣ 
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

//��ӱ� 
//ϡ��ͼ 
template <typename Weight> 
class SparseGraph{
	private:
		int n,m;//n������ m �߸���
		bool isdirected;//�Ƿ�����
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
		
		void addEdge(int v,int w,Weight weight)
		{
			assert(v>=0&&v<n);
			assert(v>=0&&v<n);
			

			// ע��, �������ڽӱ�����, �����Ƿ����ر���Ҫ������������
            // ���ǵĳ��������رߵĳ���	
            
			g[v].push_back(new Edge<Weight>(v,w,weight));
			if(v!=w&&isdirected)
				g[w].push_back(new Edge<Weight>(w,v,weight));
			
			m++;	
			return;
		}
		// ��ʾͼ����Ϣ
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
