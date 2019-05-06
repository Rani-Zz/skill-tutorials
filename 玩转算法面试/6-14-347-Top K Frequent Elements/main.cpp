class Solution {
public:
    /**
    *维护大小为k的最小优先队列 
    *要用map统计次数吗 肯定要
    *优先队列根据次数排序 最小堆
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()||k<1)
            return vector<int>{};
        priority_queue<pair<int,int>,vector<pair<int,int>>
            ,greater<pair<int,int>>> q;//<频率，元素>
        unordered_map<int,int> freq;//<元素，频率>
        for(auto i:nums)
        {
            freq[i]++;
        }
        unordered_map<int,int>::iterator it = freq.begin();
        while(it!=freq.end())
        {
            if(q.size()<k)
            {
                q.push(make_pair(it->second,it->first));
            }else
            {
                
                if(q.top().first<it->second)
                {
                    q.pop();
                    q.push(make_pair(it->second,it->first));
                }
            }
            it++;
        }
        
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
        
    }
};
