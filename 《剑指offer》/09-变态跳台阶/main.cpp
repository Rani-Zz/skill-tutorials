class Solution {
public:
    /**
    *动态规划
    *时间复杂度O(n^2)
    */
    int jumpFloorII(int number) {
        if(number<2)
            return number;
        vector<int> memo(number+1,0);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2;i<=number;i++)
        {
           //求memo[i]
            for(int j = 0;j<i;j++)
                memo[i]+=memo[j];
        }
        return memo[number];
    }
};