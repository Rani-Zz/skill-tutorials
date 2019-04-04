class Solution {
private:
    priority_queue<int,vector<int>> p;
    priority_queue<int,vector<int>,greater<int>> q;
public:
    /**
    *维护priority_queuue 
    *实现两个堆，最大堆和最小堆，且保证两个堆个数相差不超过，且最大堆比最小堆多一个，
    *这个奇数个数的话就可以直接去最大堆得top
    *最大堆里面保存前半部分 [大....小]所以读入的数小于top则push否则push到最小堆里
    *最小最里面保存后半部分 [小....大]
    *最后两个队列个数相同的话，说明两个的top保存了中位数要求平均
    *
    */
    void Insert(int num)
    {
        if(p.empty()||num<=p.top()) 
            p.push(num);
        else
            q.push(num);
        if((p.size()-q.size())==2)
        {
            q.push(p.top());
            p.pop();
        }   
        if(q.size()-p.size()==1)
        {
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    { 
        if(p.size()==q.size())
            return (p.top()+q.top())/2.0;
        else
            return p.top();
    }

};