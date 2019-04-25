class Solution {
public:
    /**
    *lis[i] 为以第i个数字结尾的上升子序列长度
    *lis[i] = max(lis[i],lis[j]+1)
    *如果数组不为空的话，最长上升子序列最少是1
    *还要有一个变量保存结果
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int res = 1;
        int n = nums.size();
        vector<int> lis(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
            
            res = max(res,lis[i]);
        }
        
        return res;
    }
};
