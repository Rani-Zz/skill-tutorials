class Solution {
public:
    /**
    *dp[i][j]:表示到长度为i的t1和长度为j的t2的最长公共子序列
    *dp[i][j] = t1[i]==t2[j] dp[i-1][j-1]+1 
    *           t1[i]!=t2][j] max(dp[i-1][j],dp[i][j-1])
    */
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty()||text2.empty())
            return 0;
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};