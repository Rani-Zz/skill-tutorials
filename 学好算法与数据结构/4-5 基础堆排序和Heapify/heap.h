#include <iostream>

using namespace std; 
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
		
		//heapify ��һ������
		//ȫ������󣬴ӵ�һ������Ҷ�ڵ�ĸ���ʼ�µ� 
		MaxHeap(vector<Item> nums,int n)
		{
			data = new Item[n+1];
			for(int i = 0;i<n;i++)
			{
				data[i+1] = nums[i];
			}
			count = n;
			for(int i = count/2;i>=1;i--)
			{
				shiftDown(i);
		    }			
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
