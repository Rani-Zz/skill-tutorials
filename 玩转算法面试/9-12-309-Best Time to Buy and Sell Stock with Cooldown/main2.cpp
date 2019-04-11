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
    *空间复杂度 O(n) 用滚动数组降维 O(1)
    *因为只跟前一天的结果有关，用三个值表示
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        
        int rest = 0,sold = 0,hold = INT_MIN;
        for(auto price: prices)
        {
            int pre_sold  = sold;
            sold = hold + price;
            hold = max(hold,rest-price);
            rest = max(rest,pre_sold);
            
        }
        
        return max(rest,sold);
    }
};
