class Solution {
private:
    void generate(vector<vector<int>> &res,vector<int> nums,int k)
    {
        if(k==nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        for(int i = k;i<nums.size();i++)
        {
            swap(nums[i],nums[k]);
            generate(res,nums,k+1);
            swap(nums[i],nums[k]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> res;
        generate(res,nums,0);
        return res;
    }
};