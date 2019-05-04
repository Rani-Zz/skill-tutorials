#include <iostream>

using namespace std; 
//索引堆 
template<typename Item> 
class IndexMaxHeap
{
private:
		Item* data;
		int* indexes;//存放索引 
		int count;
		int capacity;
	    //上调 跟父结点比较 交换 
		void shiftUp(int k)
		{
			while(k>1&&data[k/2]<data[k])
			{
				swap(data[k/2],data[k]);
				k/=2;
			 } 
		}
		//下调 跟左右子树中最大的交换,直到大于子树 
		void shiftDown(int k)
		{
			while(2*k<=count) //子树存在 
			{
				int j = 2*k;//此轮循环中，交互data[k]和data[j]
				if(j+1<=count&&data[indexes[j+1]]>data[indexes[j]])
				{
					j++;
				} 
				 // data[j] 是 data[2*k]和data[2*k+1]中的最大值
				 if(data[indexes[k]]>=data[indexes[j]])
				 break;
				 swap(indexes[k],indexes[j]);
				 
				 k = j;				
			}
		}
    public:
    	//构造函数 ,最多可容纳 capacity个元素 
	 	IndexMaxHeap(int capacity)
	 	{
	 		data = new Item[capacity+1];//容量，元素从下标为1开始存，所以capacity+1 
	 		indexes = new int[capacity+1];
	 		count = 0;
		}
		
	
		//析构函数 
	 	~IndexMaxHeap()
	 	{
	 		delete[] data;
	 		delete[] indexes;
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
		
		//插入元素 在位置i插入元素x 
		void insert(Item x,int i)
		{
			i+=1; 
			data[i] = x;
			indexes[count+1] = i;
			count++;
			shiftUp(count);
		} 
		
		//取出元素
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
}; 
