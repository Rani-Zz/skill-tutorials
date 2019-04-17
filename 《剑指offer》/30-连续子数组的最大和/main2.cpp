class Solution {
public:
    /**
    *动态规划
    *dp[i]表示以第i个字母结尾的最长最大和
    *然后选最大
    *dp[i] = max(dp[i-1]+a[i],a[i])
    *空间复杂度可以将到O（1）
    *只保留前面的结果 滚动
    *最优子结构，每一步都取最大值
    */
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        if(n==0) return 0;
        if(n==1) return array[0];
        if(n==2) return max(array[0],array[1]);
        
        int cur = array[0];
        int res = cur;
        for(int i = 1;i<n;i++)
        {
            cur = max(cur+array[i],array[i]);
            res = max(res,cur);
        }
        return res;
    }
};
