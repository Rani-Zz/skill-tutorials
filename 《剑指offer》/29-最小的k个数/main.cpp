class Solution {
public:
    /**
    *维护一个包含k个数字的pq
    *用最大堆
    */
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty()||k>input.size()||k<1)
            return res;
        priority_queue<int, vector<int>> pq;
        for(int i = 0;i<input.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(input[i]);
            }else if(input[i]<pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};