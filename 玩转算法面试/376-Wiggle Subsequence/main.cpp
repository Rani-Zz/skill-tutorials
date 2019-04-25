class Solution {
public:
    /**
    ��̬�滮
    �������壺up(i) ��ʾ�Ե�i�����ֽ�β������Ϊ�����������������һ�����ֱ�ǰһ�����󣩵���󳤶�
             dowm(i)��ʾ�Ե�i�����ֽ�β���������½��������������һ�����ֱ�ǰһ������С������󳤶�
    ״̬��ת�ƣ�up(i) = max(up(i),1+dowm(j)���nums[j]<nums[i]�Ļ�)
               dowm(i) = max(down(i),1+up(j)���nums[j]>nums[i]�Ļ�)
    �����up��down��ѡ�����ֵ
    
    */
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        
        vector<int> up(n,1);
        vector<int> down(n,1);
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    up[i] = max(up[i],1+down[j]);
                if(nums[j]>nums[i])
                    down[i] = max(down[i],1+up[j]);
            }
        }
        
        int res = 0;
        for(int i = 0;i<n;i++)
            res = max(res,up[i]);
        
        for(int j = 0;j<n;j++)
            res = max(res,down[j]);
        
        
        return res;
    }
};
