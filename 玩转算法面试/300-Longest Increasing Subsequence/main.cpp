class Solution {
public:
    /**
    LIS
    �������壺lis(i) �Ե�i�����ֽ�β������������еĳ���
    ״̬ת�ƣ�lis��i�� = max(lis(i),1+lis(j)���nums[i]>nums[j]�Ļ���˼�ǵ�ǰ�����ֿ��Ժ��Ե�j�����ֽ�β������������������У����Գ���Ϊlis(j)+1)
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        vector<int> memo(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    memo[i] = max(memo[i],1+memo[j]);
            }
        }
        
        //����memo[i]��ֵΪ�Ե�i�����ֽ�β������������еĳ���
        //ѭ��ѡ�����ֵ
        int res = 0;
        for(int i = 0;i<n;i++)
            res = max(res,memo[i]);
        
        return res;
    }
};
