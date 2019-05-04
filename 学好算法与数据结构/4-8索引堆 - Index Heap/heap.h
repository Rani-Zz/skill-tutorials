#include <iostream>

using namespace std; 
//������ 
template<typename Item> 
class IndexMaxHeap
{
private:
		Item* data;
		int* indexes;//������� 
		int count;
		int capacity;
	    //�ϵ� �������Ƚ� ���� 
		void shiftUp(int k)
		{
			while(k>1&&data[indexes[k/2]]<data[indexes[k]])
			{
				swap(indexes[k/2],indexes[k]);
				k/=2;
			 } 
		}
		//�µ� ���������������Ľ���,ֱ���������� 
		void shiftDown(int k)
		{
			while(2*k<=count) //�������� 
			{
				int j = 2*k;//����ѭ���У�����data[k]��data[j]
				if(j+1<=count&&data[indexes[j+1]]>data[indexes[j]])
				{
					j++;
				} 
				 // data[j] �� data[2*k]��data[2*k+1]�е����ֵ
				 if(data[indexes[k]]>=data[indexes[j]])
				 break;
				 swap(indexes[k],indexes[j]);
				 
				 k = j;				
			}
		}
    public:
    	//���캯�� ,�������� capacity��Ԫ�� 
	 	IndexMaxHeap(int capacity)
	 	{
	 		data = new Item[capacity+1];//������Ԫ�ش��±�Ϊ1��ʼ�棬����capacity+1 
	 		indexes = new int[capacity+1];
	 		count = 0;
		}
		
	
		//�������� 
	 	~IndexMaxHeap()
	 	{
	 		delete[] data;
	 		delete[] indexes;
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
		
		//����Ԫ�� ��λ��i����Ԫ��x 
		void insert(Item x,int i)
		{
			i+=1; 
			data[i] = x;
			indexes[count+1] = i;
			count++;
			shiftUp(count);
		} 
		
		//ȡ��Ԫ��
		Item extractMax()
		{
			Item res = data[indexes[1]];
			swap(indexes[1],indexes[count]);
			count--;
			shiftDown(1);
			return res;			
		}
		
		Item getMax()
		{
			return data[indexes[1]];
		}	
	//�޸��±�Ϊi�����ݣ��õ�������0��ʼ
	//������data��Ӧ���±�Ϊi+1��λ�� 
	void change(int i,Item newItem)
	{
		i+=1;
		data[i] = newItem;
		//ά����Ӧ������λ��
		//���ҵ����ڵ�������indexes�е�λ�ã���ȥ������
		//˳����ң� ����ʱ�临�Ӷ�O(n) 
		for(int j=1;j<=count;j++)
		{
			if(indexes[j]==i)
			{
				shiftUp(j);
				shiftDown(j);
				
				return;
			}
		 } 
	}
}; 
