class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> nums,int k,vector<int> p,int index)
    {
        if(p.size()==k)
        {
            res.push_back(p);
            return;
        }
        if(index>=nums.size())
            return;
        for(int i = index;i<nums.size();i++)
        {
            if(i>index&&nums[i]==nums[i-1])
                continue;
            p.push_back(nums[i]);
            generate(nums,k,p,i+1);
            p.pop_back();
        }
        
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i++)
        {
            vector<int> p;
            generate(nums,i,p,0);
        }
        
        res.push_back(vector<int>{});
        res.push_back(nums);
        return res;
    }
};
