class Solution {
public:
    /**
    *��set
    *����Ԫ�أ���set�в��ң�������ֹ�return
    *�������set
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
