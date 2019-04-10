class Solution {
public:
    /**
    *使用map 遍历数组看map中是否有加起来为目标值得数
    *map中存放的是<元素，下标>
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return vector<int>{mp[target-nums[i]],i};
            }
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};