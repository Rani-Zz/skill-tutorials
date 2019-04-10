class Solution {
public:
    /**
    *��������+���ұ�
    *setֻ���浱ǰԪ��ǰ��k��Ԫ��
    *���ҵ�ʱ����nums[j]-nums[i]<=t��nums[i]-nums[j]<=t
    *lower_bound���ֲ��� nums[j]>=nums[i]-t��nums[j]<=nums[i]+t
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> rec;
        for(int i = 0;i<nums.size();i++)
        {
            auto it = rec.lower_bound((long long)nums[i]-(long long)t);
            if(it!=rec.end()&&*it<=(long long)nums[i]+(long long)t)
                return true;
            rec.insert((long long)nums[i]);
            if(rec.size()>k)
                rec.erase(nums[i-k]);
        }
        return false;
    }
};
