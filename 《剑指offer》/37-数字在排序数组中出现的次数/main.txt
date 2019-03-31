class Solution {
private:
    int binarySearch(vector<int> data,int k,int low,int high)
    {
        while(low<=high)
        {
            int mid = (high+low)/2;
            if(data[mid]>k)
                high = mid-1;
            else if(data[mid]<k)
                low = mid+1;
            else
                return mid;
        }
        
        return -1;
    }
public:
    /**
    *看见有序，用二分查找
    *找到这个数以后，左右统计
    *默认数组升序
    */
    int GetNumberOfK(vector<int> data ,int k) {
        int res = 0;
        if(data.empty())
            return 0;
        int index = binarySearch(data,k,0,data.size()-1);
        if(index == -1)
            return 0;
        res = 1;
        int m = index-1,n = index+1;
        while(m>=0&&data[m]==k)
        {
            res++;m--;
        }
        while(n<=data.size()-1&&data[n]==k)
        {
            res++;n++;
        }
        
        return res;
    }
};