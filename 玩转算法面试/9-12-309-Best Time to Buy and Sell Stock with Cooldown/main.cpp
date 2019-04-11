class Solution {
public:
    /**
    *画状体图
    *每一天会有三种状态：hold，rest，sold
    *hold[i] rest[i] sold[i]分别表示这三种状态下可获得的最大值
    *状态转移：
    *hold[i] :max(hold[i-1], res[i-1] - price[i])
    *sold[i] :hold[i-1] + price[i]
    *rest[i] :max(rest[i-1], sold[i-1])
    *初始化:rest[0] = 0, sold[0] = 0,hold[0] = INT_MIN
    *结果 max(rest[i],sold[i])
    *时间复杂度 O(n)
    *空间复杂度 O(n)
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return  0;
        vector<int> rest(n+1,-1);
        vector<int> sold(n+1,-1);
        vector<int> hold(n+1,-1);
        rest[0] = 0;
        sold[0] = 0;
        hold[0] = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            hold[i+1] = max(hold[i],rest[i]-prices[i]);
            sold[i+1] = hold[i]+prices[i];
            rest[i+1] = max(rest[i],sold[i]);
        }
        
        return max(rest[n],sold[n]);
    }
};
