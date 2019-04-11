class Solution {
public:
    /**
    *��״��ͼ
    *ÿһ���������״̬��hold��rest��sold
    *hold[i] rest[i] sold[i]�ֱ��ʾ������״̬�¿ɻ�õ����ֵ
    *״̬ת�ƣ�
    *hold[i] :max(hold[i-1], res[i-1] - price[i])
    *sold[i] :hold[i-1] + price[i]
    *rest[i] :max(rest[i-1], sold[i-1])
    *��ʼ��:rest[0] = 0, sold[0] = 0,hold[0] = INT_MIN
    *��� max(rest[i],sold[i])
    *ʱ�临�Ӷ� O(n)
    *�ռ临�Ӷ� O(n) �ù������齵ά O(1)
    *��Ϊֻ��ǰһ��Ľ���йأ�������ֵ��ʾ
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
