class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        //第一行 只能加左边的
        for(int j = 1;j<n;j++)
            grid[0][j]+=grid[0][j-1];
        
        for(int i = 1;i<m;i++)
        {
            grid[i][0]+=grid[i-1][0];
            for(int j = 1;j<n;j++)
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
        }
        
        return grid[m-1][n-1];
    }
};
