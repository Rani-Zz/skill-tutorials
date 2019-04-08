class Solution {
public:
    /**
    *��map�� ��ɵ��ʵ���ĸΪkey
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;
        map<string,vector<string>> mp;
        for(auto s:strs)
        {
            string t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        
        for(auto list:mp)
            res.push_back(list.second);
        return res;
    }
};
