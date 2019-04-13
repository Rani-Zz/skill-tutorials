class Solution {
public:
    /**
    *背包问题
    *滚动数组
    */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums)
            sum+=i;
        
        if(sum%2)
            return false;
        
        int C = sum/2;
        vector<int> dp(C+1,-1);
        for(int i = 0;i<=C;i++)
            dp[i] = nums[0]==i? 1 : 0;
        
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = C;j>=nums[i];j--)
                dp[j] = dp[j]|| dp[j-nums[i]];
        }
        
        return dp[C];
    }
};
