class Solution {
public:
    /**
    *��������+���ұ�
    *��set����
    *����ʱ����set���Ƿ����
    *set��ֻ���浱ǰԪ��ǰ��k��Ԫ��
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
