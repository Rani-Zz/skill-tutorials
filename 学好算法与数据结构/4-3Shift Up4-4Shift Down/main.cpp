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
	    //上调 跟父结点比较 交换 
		void shiftUp(int k)
		{
			while(k>2&&data[k/2]<data[k])
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
				if(j+1<=count&&data[j+1]>data[j])
				{
					j+1;
				} 
				 // data[j] 是 data[2*k]和data[2*k+1]中的最大值
				 if(data[k]>=data[j])
				 break;
				 swap(data[k],data[j]);
				 
				 k = j;				
			}
		}
    public:
    	//构造函数 ,最多可容纳 capacity个元素 
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
		
		//插入元素
		void insertItem(Item x)
		{
			data[count+1] = x;
			count++;
			shiftUp(count);
		} 
		
		//取出元素
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
