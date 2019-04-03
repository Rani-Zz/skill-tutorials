class Solution {
public:
    /**
    *��ĸ������ͬ������˳��һ��
    *������map����
    *���������������Ϊ��
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