class Solution {
public:
    /**
    *dp[i]:表示组成i有几种方式
    *dp[i] = dp[i]+dp[i-nums[j]]
    */
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0] = 1;
        
        for(long long i = 1;i<=target;i++)
        {
            for(long long j = 0;j<nums.size();j++)
            {
                if(i>=nums[j])
                  dp[i] = dp[i]+dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
