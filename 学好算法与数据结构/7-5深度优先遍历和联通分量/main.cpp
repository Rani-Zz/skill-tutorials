#include <iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<cassert> 

using namespace std; 

//��ͼ����ͨ���� 
template <typename Graph>
class Component{
	private:
		Graph &g;
		bool* visited;//��¼dfs�Ĺ����н���Ƿ񱻷��� 
		int count;//��¼��ͨ�������� 
		int *id;//ÿ���������Ӧ����ͨ�������
		
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
		 // ���캯��, �����Ȩͼ����ͨ����
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
			
			//��ͼ����ͨ����
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
		 
		 //������ͨ��������
		 int getCount()
		 {
		 	return count;
		  } 
		  
		  //�ж���������Ƿ���ͨ
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
