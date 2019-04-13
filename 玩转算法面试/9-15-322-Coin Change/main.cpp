class Solution {
public:
    /**
    *背包问题 填满amount
    *dp[i]:表示填满i所需的数量
    */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(auto coin:coins)
        {
            for(int i = coin;i<=amount;i++)
            {
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
