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
    	//���캯�� 
	 	MaxHeap(int capacity)
	 	{
	 		data = new Item[capacity+1];//������Ԫ�ش��±�Ϊ1��ʼ�棬����capacity+1 
	 		count = 0;
		}
		//�������� 
	 	~MaxHeap()
	 	{
	 		delete[] data;
		}
		//Ԫ�ظ��� 
		int size()
		{
			return count;
		}
		//�Ƿ�Ϊ�� 
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
