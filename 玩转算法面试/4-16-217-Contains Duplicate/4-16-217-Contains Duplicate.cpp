class Solution {
public:
    /**
    *用set
    *遍历元素，在set中查找，如果出现过return
    *否则存入set
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> rec;
        for(int i = 0;i<nums.size();i++)
        {
            if(rec.find(nums[i])!=rec.end())
                return true;
            rec.insert(nums[i]);
        }
        return false;
    }
};
