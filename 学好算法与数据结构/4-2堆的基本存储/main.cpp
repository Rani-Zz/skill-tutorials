#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename Item>
class MaxHeap
{
	private:
		Item* data;
		int count;
    public:
    	//构造函数 
	 	MaxHeap(int capacity)
	 	{
	 		data = new Item[capacity+1];//容量，元素从下标为1开始存，所以capacity+1 
	 		count = 0;
		}
		//析构函数 
	 	~MaxHeap()
	 	{
	 		delete[] data;
		}
		//元素个数 
		int size()
		{
			return count;
		}
		//是否为空 
		bool isEmpty()
		{
			return count==0;
		}
};
int main() {
	
	MaxHeap<int> maxhaep =  MaxHeap<int>(10);
	cout<<maxhaep.size()<<endl;
	return 0;
}
