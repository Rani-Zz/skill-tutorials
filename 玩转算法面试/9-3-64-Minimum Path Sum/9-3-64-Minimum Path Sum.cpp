class Solution {
public:
    /**
    *从左上到右下和最小，每次只能向下或向右
    *最后和最小，最优子结构g[i][j]+=min(g[i-1][j],g[i][j-1])
    *但是注意第一行只能向右 g[0][j] +=g[0][j-1]
    *第一列只能向下 g[i][0]+=g[i-1][0]
    *效率不是很高，有待改进
    */
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
         int m = grid.size(),n = grid[0].size();
        //第一行
        for(int j = 1;j<n;j++)
            grid[0][j]+=grid[0][j-1];
        //第一列
        for(int i = 1;i<m;i++)
            grid[i][0]+=grid[i-1][0];
        
        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        }
        
       
        return grid[m-1][n-1];
    }
};
