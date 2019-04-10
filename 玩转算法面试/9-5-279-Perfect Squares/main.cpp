class Solution {
public:
    /**
    *每个数可以分成1*1,....,j*j
    *memo[i]：表示分解i获取的最小个数
    *memo[i] = min(memo[i],memo[i-j*j]+1)
    *用图的那种方法应该效率更高
    */
    int numSquares(int n) {
        if(n<2)
            return n;
        vector<int> memo(n+1,INT_MAX);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j*j<=i;j++)
                memo[i] = min(memo[i],memo[i-j*j]+1);
        }
        
        return memo[n];
    }
};
