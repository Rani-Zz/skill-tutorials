class Solution {
public:
    /**
    *dp[i] = max(dp[i], j*dp[i-j])
    */
    int cutRope(int number) {
        if(number<2)
            return 0;
        if(number==2)
            return 1;
        if(number==3)
            return 2;
        vector<int> dp(number+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 4;i<=number;i++)
        {
            for(int j = 1;j<i;j++)
                dp[i] = max(dp[i],j*dp[i-j]);
        }
        
        return dp[number];
    }
};