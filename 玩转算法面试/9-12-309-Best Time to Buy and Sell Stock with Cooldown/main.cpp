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
    *�ռ临�Ӷ� O(n)
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
