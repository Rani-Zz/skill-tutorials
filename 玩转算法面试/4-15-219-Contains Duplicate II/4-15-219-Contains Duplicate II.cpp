class Solution {
public:
    /**
    *滑动窗口+查找表
    *用set保存
    *遍历时查找set中是否存在
    *set中只保存当前元素前的k个元素
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> rec;
        for(int i = 0;i<nums.size();i++)
        {
            if(rec.find(nums[i])!=rec.end())
                return true;
            rec.insert(nums[i]);
            if(rec.size()>k)
                rec.erase(nums[i-k]);
        }
        return false;
    }
};
