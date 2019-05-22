class Solution {
public:
    /**
    *�����ϵ����º���С��ÿ��ֻ�����»�����
    *������С�������ӽṹg[i][j]+=min(g[i-1][j],g[i][j-1])
    *����ע���һ��ֻ������ g[0][j] +=g[0][j-1]
    *��һ��ֻ������ g[i][0]+=g[i-1][0]
    *Ч�ʲ��Ǻܸߣ��д��Ľ�
    */
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
         int m = grid.size(),n = grid[0].size();
        //��һ��
        for(int j = 1;j<n;j++)
            grid[0][j]+=grid[0][j-1];
        //��һ��
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
