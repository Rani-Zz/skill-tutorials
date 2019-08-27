class Solution {
public:
    /**
    *dp[i][j]: true 表示是s[i]...s[j]回文的
    *dp[i][j] = dp[i+1][j-1]&&s[i]==s[j]
    *base:dp[i][i] = true
    *      dp[i][i+1] s[i]==s[i+1]
    */
    string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //base
        for(int i = 0;i<n;i++)
        {
            dp[i][i] = true;
            if(i+1<n)
             dp[i][i+1] = s[i]==s[i+1]?true:false;
        }
        
        //dp
        for(int i = n-3;i>=0;i--)
        {
            for(int j = i+2;j<n;j++)
            {
                dp[i][j] = dp[i+1][j-1]&&s[i]==s[j];
            }
        }
        
        string str;
        int len = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(dp[i][j])
                {
                    if(j-i+1>len)
                    {
                        len = j-i+1;
                        str = s.substr(i,j-i+1);
                    }
                }
            }
        }
        
        return str;
    }
    
};