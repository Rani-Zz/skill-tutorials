class Solution {
public:
    /**
    *ÿ�������Էֳ�1*1,....,j*j
    *memo[i]����ʾ�ֽ�i��ȡ����С����
    *memo[i] = min(memo[i],memo[i-j*j]+1)
    *��ͼ�����ַ���Ӧ��Ч�ʸ���
    */
    int numSquares(int n) {
        if(n<2)
            return n;
        vector<int> memo(n+1,INT_MAX);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j*j<=i;j++)
                memo[i] = min(memo[i],memo[i-j*j]+1);
        }
        
        return memo[n];
    }
};
