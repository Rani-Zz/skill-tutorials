class Solution {
public:
    /**
    *memo[i][j]:表示达到点i,j有几种方式
    *memo[i][j] = memo[i-1][j]+memo[i][j-1]
    *但是要考虑memo[i][j]是否有障碍，有障碍就不能到达
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        if(m==0||n==0||obstacleGrid[0][0])
            return 0;
        vector<vector<long>> memo(m,vector<long>(n,-1));
        memo[0][0] = 1;
        //第一行
        for(int j = 1;j<n;j++)
        {
            memo[0][j] = obstacleGrid[0][j]? 0:  memo[0][j-1];
        }
        for(int i = 1;i<m;i++)
        {
            memo[i][0] = obstacleGrid[i][0]?0: memo[i-1][0];
        }
        for(long i = 1;i<m;i++)
        {
            for(long j = 1;j<n;j++)
            {
                memo[i][j] = obstacleGrid[i][j]?0:memo[i-1][j]+memo[i][j-1];
            }
        }
        return memo[m-1][n-1];
    }
};
