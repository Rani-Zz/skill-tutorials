class Solution {
public:
    /**
    *从上到下往下加，最后在最后一行的结果中选出最小的就行
    *要最后的结果最小，所以最优子结构，每一步都选相邻元素中最小的哪个加
    *但是注意t[i][0]相邻的元素只有一个t[i-1][0]
    *t[i][i]相邻的也只有一个t[i-1][i-1]
    *其他t[i][j] +=min(t[i-1][j],t[i-1][j-1])
    *不需要额外的数组，在原基础上直接加就可以了
    */
    int minimumTotal(vector<vector<int>>& triangle) {

        if(triangle.empty())
            return 0;
        int n = triangle.size();
        for(int i =1;i<n;i++)
        {
            triangle[i][0]+=triangle[i-1][0];
            triangle[i][i]+=triangle[i-1][i-1];
            for(int j = 1;j<i;j++)
                triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
        }
        
        int res = INT_MAX;
        for(int i = 0;i<n;i++)
            res = min(res,triangle[n-1][i]);
        return res;
    }
};
