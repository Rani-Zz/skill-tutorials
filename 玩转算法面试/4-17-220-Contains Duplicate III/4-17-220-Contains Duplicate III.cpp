class Solution {
public:
    /**
    *滑动窗口+查找表
    *set只保存当前元素前的k个元素
    *查找的时候找nums[j]-nums[i]<=t或nums[i]-nums[j]<=t
    *lower_bound二分查找 nums[j]>=nums[i]-t且nums[j]<=nums[i]+t
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
