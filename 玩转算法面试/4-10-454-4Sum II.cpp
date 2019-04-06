class Solution {
public:
    /**
    *把两个的和保存在map中
    *遍历另外两个的时候去找
    */
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        int res = 0;
        for(auto i:A)
        {
            for(auto j:B)
                mp[i+j]++;
        }
        for(auto i:C)
        {
            for(auto j:D)
            {
                if(mp.find(-i-j)!=mp.end())
                    res+=mp[-i-j];
            }
        }
        
        return res;
    }
};