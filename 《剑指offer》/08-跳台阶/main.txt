class Solution {
public:
    /**
    *斐波那契数列问题
    *递归函数定义：f(n)表示上n级台阶的方法数
    *状态转移：f(n) = f(n-1)+f(n-2)
    *使用动态规划 memo的更新方式与递归函数逻辑相同
    *时间复杂度o(n) 空间复杂度o(n)
    */
    int jumpFloor(int number) {
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