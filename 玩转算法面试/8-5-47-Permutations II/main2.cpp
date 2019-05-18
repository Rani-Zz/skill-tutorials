class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generate(vector<int> nums,int k,vector<int> p)
    {
        if(k==nums.size())
        {
            res.push_back(p);
            return ;
        }
        for(int i = 0 ;i<nums.size();i++)
        {
            if(!used[i])
            {
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1])
                    continue;
                
                p.push_back(nums[i]);
                used[i] = true;
                generate(nums,k+1,p);
                p.pop_back();
                used[i] = false;
            }
        }
        
        return;
    }
public:
    /**
    *含重复数字，先把nums排序，组合的时候跳过重复
    *1 1 
    *遍历到第二个1时如果第一个1已经在组合中了那第二个1还可以在出现
    *如果不在组合中，就continue，不再组合中说明要以这个数字为开头做组合，这个数字已经第二次出现了，所以以它为开头的组合已经做过一次了，不需要再重复，所以跳过
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return res;
        used = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        vector<int> p;
        generate(nums,0,p);
        return res;
    }
};
