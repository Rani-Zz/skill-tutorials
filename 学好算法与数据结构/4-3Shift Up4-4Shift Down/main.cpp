#include <iostream>
#include<vector>
#include<ctime>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename Item>
class MaxHeap
{
	private:
		Item* data;
		int count;
	    //�ϵ� �������Ƚ� ���� 
		void shiftUp(int k)
		{
			while(k>2&&data[k/2]<data[k])
			{
				swap(data[k/2],data[k]);
				k/=2;
			 } 
		}
		//�µ� ���������������Ľ���,ֱ���������� 
		void shiftDown(int k)
		{
			while(2*k<=count) //�������� 
			{
				int j = 2*k;//����ѭ���У�����data[k]��data[j]
				if(j+1<=count&&data[j+1]>data[j])
				{
					j+1;
				} 
				 // data[j] �� data[2*k]��data[2*k+1]�е����ֵ
				 if(data[k]>=data[j])
				 break;
				 swap(data[k],data[j]);
				 
				 k = j;				
			}
		}
    public:
    	//���캯�� ,�������� capacity��Ԫ�� 
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
		
		//����Ԫ��
		void insertItem(Item x)
		{
			data[count+1] = x;
			count++;
			shiftUp(count);
		} 
		
		//ȡ��Ԫ��
		Item extractMax()
		{
			Item res = data[1];
			swap(data[1],data[count]);
			count--;
			shiftDown(1);
			
			return res;			
		}
		
		Item getMax()
		{
			return data[1];
		}
};
int main() {
	
	MaxHeap<int> maxheap =  MaxHeap<int>(10);
	cout<<maxheap.size()<<endl;
	
	srand(time(NULL));
	for(int i = 0;i<10;i++)
	{
		maxheap.insertItem(rand()%10);
	}
	
	int n = maxheap.size();
	vector<int> nums(maxheap.size(),0);
	for(int i = n-1;i>=0;i--)
	{
		nums[i] = maxheap.extractMax();
	}
	for(auto i:nums)
	{
		cout<<i<<" "; 
	}
	return 0;
}
