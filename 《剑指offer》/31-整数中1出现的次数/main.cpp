class Solution {
public:
    /**
    *个位：每10个出现一次 n/10*1 + k = n%10 <1不会有了 否则+1
    *十位：每100个出现10次 n/100*10 k = n%100 >19 +10 <10+1 之间 k-10+1
    *百位：每1000个出现100次 n/1000*100 k = n%1000 k = n%1000 >199 +100 <0 +10 之间+k-100+1
    *总结 (n/(i*10)) *i + (如果n%（i*10）>2*i-1) +i  <i+0 否则k-i+1
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