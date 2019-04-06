class Solution {
public:
    /**
    *用map保存freq
    *然后遍历将次数相同的放到一起，用元素为string的vctor保存
    *最后遍历vector就可以了
    */
    string frequencySort(string s) {
        string res;
        if(s.empty()) return res;
        unordered_map<char,int> freq;
        int maxCount = INT_MIN;
        for(auto c:s)
        {
            freq[c]++;
            maxCount = max(maxCount,freq[c]);
        }  
        
        vector<string> bucket(maxCount+1,"");
        for(auto i:freq)
        {
            int n = i.second;
            int c = i.first;
            bucket[n].append(n,c);
        }
        
        for(int i = bucket.size()-1;i>0;i--)
        {
            if(bucket[i].size()!=0)
                res+=bucket[i];
        }
        return res;
    }
};