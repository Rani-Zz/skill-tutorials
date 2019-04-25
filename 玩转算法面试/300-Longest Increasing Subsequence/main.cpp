class Solution {
public:
    /**
    LIS
    函数定义：lis(i) 以第i个数字结尾的最长上升子序列的长度
    状态转移：lis（i） = max(lis(i),1+lis(j)如果nums[i]>nums[j]的话意思是当前的数字可以和以第j个数字结尾的序列组成上升子序列，所以长度为lis(j)+1)
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> memo(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    memo[i] = max(memo[i],1+memo[j]);
            }
        }
        
        //现在memo[i]的值为以第i个数字结尾的最长上升子序列的长度
        //循环选出最大值
        int res = 0;
        for(int i = 0;i<n;i++)
            res = max(res,memo[i]);
        
        return res;
    }
};
