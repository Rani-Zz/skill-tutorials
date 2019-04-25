class Solution {
public:
    /**
    *up[i]:��ʾ�Ե�i�����ֽ�β������������i��ǰһ�����ִ�
    *down[i]:��ʾ�Ե�i�����ֽ�β���½�������i��ǰһ����С
    *����,�ѵ�i�����ָ�ǰ������Ƚ�
    *״̬ת�� j<i up[i] = max(up[i],down[j]+1)
    *        j>i down[i] = max(down[i],up[j]+1)
    *���nums��Ϊ�յĻ� res������1
    */
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res = 1;
        int n = nums.size();
        vector<int> up(n,1);
        vector<int> down(n,1);
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    up[i] = max(up[i],down[j]+1);
                }
                
                if(nums[j]>nums[i])
                {
                    down[i] = max(down[i],up[j]+1);
                }
            }
        }
        
        for(auto i:up)
            res = max(res,i);
        for(auto i:down)
            res = max(res,i);
        
        return res;
    }
};
