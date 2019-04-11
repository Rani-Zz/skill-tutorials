class Solution {
public:
    /**
    *状态定义:memo[i]表示到第i个是可偷得的最大值
    *状态转移：memo[i] = max(nums[i]+memo[i-2],memo[i-1])
    *这样其实只看前面两个值，所以用两个变量记录，又可以节省空间
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        int pre = nums[0];
        int cur = max(pre,nums[1]);
        for(int i = 2;i<n;i++)
        {
            int tmp = cur;
            cur  = max(nums[i]+pre,cur);
            pre = tmp;
        }
        return cur;
    }
};
