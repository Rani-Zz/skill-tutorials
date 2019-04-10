class Solution {
public:
    /**
    *memo[i]:��ʾ��i��̨���м��ַ�ʽ
    *һ�ο�����1�׻�������
    *����memo[i] = memo[i-1]+memo[i-2]
    */
    int climbStairs(int n) {
        if(n<2)
            return n;
        vector<int> memo(n+1,-1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2;i<=n;i++)
            memo[i] = memo[i-1]+memo[i-2];
        return memo[n];
    }
};
