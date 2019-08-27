class Solution {
public:
    /**
    *dp[i]:存放长度为i+1的最长上升子序列的末位数 且是最小值
    *遍历数组nums dp[0] = nums[0]
    *nums[1]>dp[0] dp[1] = nums[i] 长度为2的子序列末尾是nums[1]
    *否则 要用更小的数字替换，用二分查找 lower_bound 会返回可插入的位置
    */
    int lengthOfLIS(vector<int>& nums) {
       if(nums.empty())
           return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]>dp.back())
                dp.push_back(nums[i]);
            else
            {
              dp[lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin()] = nums[i];   
            }
        }
        return dp.size();
    }
};