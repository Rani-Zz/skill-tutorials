class Solution {
public:
    /**
    *”√mapÕ≥º∆
    */
    int FirstNotRepeatingChar(string str) {
        int res = -1;
        if(str.empty())
            return res;
        map<char,int> mp;
        for(auto c:str)
        {
            mp[c]++;
        }
        for(int i = 0;i<str.size();i++)
        {
            if(mp[str[i]]==1)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};