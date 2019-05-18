class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generate(vector<int> nums,int index,vector<int>& p)
    {
        if(index == nums.size())
        {
           if(find(res.begin(),res.end(),p)==res.end()) res.push_back(p);
            return ;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(!used[i])
            {
                p.push_back(nums[i]);
                used[i] = true;
                generate(nums,index+1,p);
                p.pop_back();
                used[i] = false;
            }
        }
    }
public:
    /**
    按照 46的解法，如果nums中存在相同的数字，那么最后的结果中就会有重复的，
    那保存的时候如果存在就不保存,保存的时候每次都要先找一遍，这样做会很慢
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return res;
        
        vector<int> p;
        used = vector<bool>(nums.size(),false);
        generate(nums,0,p);
        
        return res;
    }
};
