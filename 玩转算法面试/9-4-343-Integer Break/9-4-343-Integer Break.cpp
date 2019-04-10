class Solution {
    int max3(int a,int b,int c)
    {
        return max(a,max(b,c));
    }
public:
    /**
    *ÿ���������Էֳ�1,...,n-1
    *memo[i]:��ʾ��i�ɻ�õ����˻� ��ʼ��Ϊ1
    *�����ӽṹ
    *memo[i] = max(memo[i],j*memo[i-j],j*(i-j))
    */
    int integerBreak(int n) {
        if(n<2)
            return n;
        vector<int> memo(n+1,1);
        for(int i = 2;i<=n;i++)
        {
            //memo[i]
            for(int j = 1;j<i;j++)
                memo[i] = max3(memo[i],j*memo[i-j],j*(i-j));
        }
        return memo[n];
    }
};
