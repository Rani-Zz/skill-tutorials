class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> nums,int k,int count,int start,vector<int> p)
    {
        if(count==k)
        {
            res.push_back(p);
            return;
        }
        if(start==nums.size())
            return;
        
        for(int i = start;i<nums.size();i++)
        {
            p.push_back(nums[i]);
            count++;
            generate(nums,k,count,i+1,p);
            p.pop_back();
            count--;
        }
        
        return;
    }
public:
    /**
    结果不可包含重复
    子集：从nums中取0个数、取1个数、取2个数、....、取nums.size()个数
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>{}); //空集
        if(nums.empty())
           return res;

        for(int k = 1;k<=nums.size()-1;k++)
        {
            vector<int> p;
            int count = 0;
            int start = 0;
            generate(nums,k,count,start,p);
        }
        
        res.push_back(nums);//全集
        
        return res;
    }
};
