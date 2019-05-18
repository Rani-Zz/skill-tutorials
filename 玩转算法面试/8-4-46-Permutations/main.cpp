class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generate(vector<int> nums,int k,vector<int> p)
    {
        if(k==nums.size())
        {
            res.push_back(p);
            return;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(!used[i])
            {
                used[i] = true;
                p.push_back(nums[i]);
                generate(nums,k+1,p);
                p.pop_back();
                used[i] = false;
            }
        }
        
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return res;
        used = vector<bool>(nums.size(),false);
        vector<int> p;
        generate(nums,0,p);
        return res;
    }
};
