class Solution {
public:
    /**
    *dp[i][u][v] 表示第i个字符串时u个0和v个1 能组成的最大个数
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> mcost(strs.size(),0);
        vector<int> ncost(strs.size(),0);
        for(int i = 0;i<strs.size();i++)
        {
            for(auto c:strs[i])
            {
                if(c=='0')
                    mcost[i]++;
                else
                    ncost[i]++;
            }
        }
        
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int u = mcost[0];u<=m;u++)
            for(int v = ncost[0];v<=n;v++)
                dp[0][u][v] = 1;
        
        for(int i = 1;i<strs.size();i++)
        {
            for(int u = 0;u<=m;u++)
            {
                for(int v = 0;v<=n;v++)
                {
                    dp[i][u][v] = dp[i-1][u][v];
                    if(u>=mcost[i]&&v>=ncost[i])
                    {
                        dp[i][u][v] = max(dp[i][u][v],
                                          dp[i-1][u-mcost[i]][v-ncost[i]]+1);
                    }
                }
            }
        }
        
        return dp[strs.size()-1][m][n];
    }
};
