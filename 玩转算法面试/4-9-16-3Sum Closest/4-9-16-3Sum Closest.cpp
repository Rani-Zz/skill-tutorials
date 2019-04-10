class Solution {
public:
    /**
    *������
    *ȷ��һ������Ȼ���ײָ��������������
    *�ҵ��;�ֱ�ӷ��أ����Ǻ;ͱȽϽӽ��̶�
    */
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int minGap = INT_MAX;
        int res = 0;
        int n = nums.size();
        for(int i = 0;i<n-2;i++)
        {
            int l = i+1,r = n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target) return sum;
                if(abs(sum-target)<minGap)
                {
                    res = sum;
                    minGap = abs(sum-target);
                }
                if(sum>target) r--;
                else l++;
            }
        }
        return res;
    }
};
