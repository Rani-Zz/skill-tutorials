class Solution {
public:
    /**
    *��̬�滮
    *ʱ�临�Ӷ� O(n) �ռ临�Ӷ�o(n)
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