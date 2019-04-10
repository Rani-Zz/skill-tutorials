class Solution {
public:
    /**
    *set
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record(nums1.begin(),nums1.end());
        set<int> resSet;
    
        for(auto i:nums2)
        {
            if(record.find(i)!=record.end())
                resSet.insert(i);
        }
        
        return vector<int>(resSet.begin(),resSet.end());
    }
};