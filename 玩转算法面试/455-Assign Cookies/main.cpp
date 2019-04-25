class Solution {
public:
    /**
    ������si�ָ�����gi���Ƿ����㣬һ�αȽ�    
    */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty()||s.empty())
            return 0;
        
        sort(g.begin(),g.end(),greater<int>{});
        sort(s.begin(),s.end(),greater<int>{});
        
        int res = 0;
        int si = 0 , gi = 0;
        while(si<s.size()&&gi<g.size())
        {
            if(s[si]>=g[gi])
            {
                res++;
                si++;
                gi++;
            }else
            {
                gi++;
            }
        }
        return res;
    }
};
