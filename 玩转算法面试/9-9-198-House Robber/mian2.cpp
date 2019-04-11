class Solution {
public:
    /**
    *״̬����:memo[i]��ʾ����i���ǿ�͵�õ����ֵ
    *״̬ת�ƣ�memo[i] = max(nums[i]+memo[i-2],memo[i-1])
    *������ʵֻ��ǰ������ֵ������������������¼���ֿ��Խ�ʡ�ռ�
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        int pre = nums[0];
        int cur = max(pre,nums[1]);
        for(int i = 2;i<n;i++)
        {
            int tmp = cur;
            cur  = max(nums[i]+pre,cur);
            pre = tmp;
        }
        return cur;
    }
};
