class Solution {
public:
    /**
    *lis[i] Ϊ�Ե�i�����ֽ�β�����������г���
    *lis[i] = max(lis[i],lis[j]+1)
    *������鲻Ϊ�յĻ��������������������1
    *��Ҫ��һ������������
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int res = 1;
        int n = nums.size();
        vector<int> lis(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
            
            res = max(res,lis[i]);
        }
        
        return res;
    }
};
