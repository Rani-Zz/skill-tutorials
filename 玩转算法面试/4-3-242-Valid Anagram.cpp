class Solution {
public:
    /**
    *字母个数相同，但是顺序不一样
    *所以用map保存
    *考虑特殊情况，都为空
    */
    bool isAnagram(string s, string t) 
    {
        if(s.empty()&&t.empty())
            return true;
        if(s.length()!=t.length())
            return false;
        map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        for(auto c:t)
        {
            if(mp[c]>0)
                mp[c]--;
            else
                return false;
        }
        return true;
    }
};