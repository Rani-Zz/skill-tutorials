class Solution {
public:
    /**
    *memo[i][j]:表示到达i,j有多少种方式
    *还是跟跳台阶一样memo[i][j] = memo[i-1][j]+memo[i][j-1]
    *
    */
    int uniquePaths(int m, int n) {
       vector<vector<int>> memo(m,vector<int>(n,1));
       for(int i = 1;i<m;i++)
       {
           for(int j = 1;j<n;j++)
               memo[i][j] = memo[i-1][j]+memo[i][j-1];
       }
        return memo[m-1][n-1];
    }
};
