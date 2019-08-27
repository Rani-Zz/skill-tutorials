class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows==1||s.empty())
           return s;
        vector<string> rows(min(numRows,(int)s.size()));
        
        int cur = 0;
        bool flag = true;
        for(auto c:s)
        {
            rows[cur] +=c;
            if(cur==numRows-1) flag = false;
            if(cur==0) flag = true;
            cur+= flag?1:-1;
        }
        string res;
        for(auto s:rows)
            res+=s;
        return res;
    }
};