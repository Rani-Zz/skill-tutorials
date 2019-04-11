class Solution {
private:
    int tryRob(vector<int> nums,int begin,int end)
    {
        int preMax = nums[begin];
        int curMax = max(preMax,nums[begin+1]);
        for(int i = begin+2;i<=end;i++)
        {
           
            int tmp = curMax;
            curMax = max(nums[i]+preMax,curMax);
            preMax = tmp;
        }
        return curMax;
    }
public:
    /**
    *偷0，不能偷n-1   不偷0，可以偷n-1
    *所以分开[0,...,n-2] [1,...,n-1]
    *这两个范围里的房子都可以都，跟HR I的情况又一样了
    *所以最后的结果就是在这两个中找最大的
    * HR I 只记录两个值 dp[i] = max(dp[i]+dp[i-2],dp[i-1])
    * pre记录i-2 cur记录i-1的值
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0) return 0;
        if(n==1)  return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(tryRob(nums,0,n-2),tryRob(nums,1,n-1));
    }
};
