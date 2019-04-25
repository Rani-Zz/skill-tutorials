class Solution {
public:
    /**
    动态规划
    函数定义：up(i) 表示以第i个数字结尾且序列为上升（即序列中最后一个数字比前一个数大）的最大长度
             dowm(i)表示以第i个数字结尾且序列且下降（即序列中最后一个数字比前一个数字小）的最大长度
    状态的转移：up(i) = max(up(i),1+dowm(j)如果nums[j]<nums[i]的话)
               dowm(i) = max(down(i),1+up(j)如果nums[j]>nums[i]的话)
    最后在up、down中选出最大值
    
    */
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        
        vector<int> up(n,1);
        vector<int> down(n,1);
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    up[i] = max(up[i],1+down[j]);
                if(nums[j]>nums[i])
                    down[i] = max(down[i],1+up[j]);
            }
        }
        
        int res = 0;
        for(int i = 0;i<n;i++)
            res = max(res,up[i]);
        
        for(int j = 0;j<n;j++)
            res = max(res,down[j]);
        
        
        return res;
    }
};
