class Solution {
private:
    int tryRob(vector<int> nums,int begin,int end)
    {
        int preMax = nums[begin];
        int curMax = max(preMax,nums[begin+1]);
        for(int i = begin+2;i<=end;i++)
        {
           
            int tmp = curMax;
            curMax = max(nums[i]+preMax,curMax);
            preMax = tmp;
        }
        return curMax;
    }
public:
    /**
    *͵0������͵n-1   ��͵0������͵n-1
    *���Էֿ�[0,...,n-2] [1,...,n-1]
    *��������Χ��ķ��Ӷ����Զ�����HR I�������һ����
    *�������Ľ����������������������
    * HR I ֻ��¼����ֵ dp[i] = max(dp[i]+dp[i-2],dp[i-1])
    * pre��¼i-2 cur��¼i-1��ֵ
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0) return 0;
        if(n==1)  return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(tryRob(nums,0,n-2),tryRob(nums,1,n-1));
    }
};
