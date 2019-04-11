class Solution {
public:
    /**
    *状态定义：从[i..,n-1]范围里选一个去偷
    *状态转移：memo[i] = max{v[i]+memo[i+2],v(i+1)+memo[i+3],...,v(n-1),v(n-1)}
    */
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> memo(n,-1);
        memo[n-1] = nums[n-1];
        for(int i = n-1;i>=0;i--)
        {
            for(int j = i;j<n;j++)
            {
                memo[i] = max(memo[i],nums[j]+(j+2<n? memo[j+2]:0));
            }
        }
        
        return memo[0];
    }
};
