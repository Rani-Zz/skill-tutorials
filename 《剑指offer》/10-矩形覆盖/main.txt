class Solution {
public:
    /**
    *动态规划
    *时间复杂度 O(n) 空间复杂度o(n)
    */
    int rectCover(int number) {
        if(number<2)
            return number;
        vector<int> memo(number+1,-1);
        memo[0] = 1;
        memo[1] = 1;

        for(int i = 2;i<=number;i++)
        {
            memo[i] = memo[i-1]+memo[i-2];
        }
        return memo[number];
    }
};