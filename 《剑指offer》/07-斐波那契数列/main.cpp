class Solution {
public:
    /**
    *¶¯Ì¬¹æ»®
    */
    int Fibonacci(int n) {
        if(n<2)
            return n;
        vector<int> memo(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            memo[i] = memo[i-1]+memo[i-2];
        }
        return memo[n];
    }
};