class Solution {
public:
    /**
    *��λ��ÿ10������һ�� n/10*1 + k = n%10 <1�������� ����+1
    *ʮλ��ÿ100������10�� n/100*10 k = n%100 >19 +10 <10+1 ֮�� k-10+1
    *��λ��ÿ1000������100�� n/1000*100 k = n%1000 k = n%1000 >199 +100 <0 +10 ֮��+k-100+1
    *�ܽ� (n/(i*10)) *i + (���n%��i*10��>2*i-1) +i  <i+0 ����k-i+1
    */
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        int count = 0;
        for(int i = 1;i<=n;i*=10)
        {
            int d = i*10;
            count+=(n/d)*i;
            int k = n%d;
            if(k>2*i-1) count+=i;
            else if(k<i) count+=0;
            else count+=k-i+1;    
        }
        return count;
    }
};