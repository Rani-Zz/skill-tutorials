class Solution {
public:
    /**
    *ά����СΪk����С���ȶ��� 
    *Ҫ��mapͳ�ƴ����� �϶�Ҫ
    *���ȶ��и��ݴ������� ��С��
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()||k<1)
            return vector<int>{};
        priority_queue<pair<int,int>,vector<pair<int,int>>
            ,greater<pair<int,int>>> q;//<Ƶ�ʣ�Ԫ��>
        unordered_map<int,int> freq;//<Ԫ�أ�Ƶ��>
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
