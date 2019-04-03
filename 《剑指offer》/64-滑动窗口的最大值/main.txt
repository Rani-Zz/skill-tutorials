class Solution {
public:
    /**
    *用deque实现 里面保存下标
    *front保存滑动窗口最大值的下标，所以每个数都从队尾入，当当前元素比队尾元素大时，队尾弹出
    *但是位于队首的最大值不在当前窗口时,从front弹出
    *这样front保存的永远是当前窗口的最大值
    *达到窗口大小时，存入结果即可
    */
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.empty()||size<1||size>num.size())
            return res;
        deque<int> d;
        for(int i = 0;i<num.size();i++)
        {
            while(d.size()&&num[d.back()]<=num[i])
                d.pop_back();
            while(d.size()&&i-d.front()+1>size)
                d.pop_front();
            d.push_back(i);
            if(i+1>=size)
                res.push_back(num[d.front()]);
        }
        
        return res;
    }
};