class Solution {
public:
    /**
    *up[i]:表示以第i个数字结尾且上升，就是i比前一个数字大
    *down[i]:表示以第i个数字结尾且下降，就是i比前一个树小
    *遍历,把第i个数字跟前面的数比较
    *状态转移 j<i up[i] = max(up[i],down[j]+1)
    *        j>i down[i] = max(down[i],up[j]+1)
    *如果nums不为空的话 res至少是1
    */
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res = 1;
        int n = nums.size();
        vector<int> up(n,1);
        vector<int> down(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    up[i] = max(up[i],down[j]+1);
                }
                
                if(nums[j]>nums[i])
                {
                    down[i] = max(down[i],up[j]+1);
                }
            }
        }
        
        for(auto i:up)
            res = max(res,i);
        for(auto i:down)
            res = max(res,i);
        
        return res;
    }
};
