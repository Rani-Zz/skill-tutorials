class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> nums,int k,int count,int start,vector<int> p)
    {
        if(count==k)
        {
            //处理包含重复元素还有没有更好的办法
            sort(p.begin(),p.end());
            if(find(res.begin(),res.end(),p)==res.end()) 
                res.push_back(p);
            return;
        }
        if(start==nums.size())
            return ;
        
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
    给的集合中可包含重复值
    但是结果中不可包含重复子集
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          res.push_back(vector<int>{});//空集
          if(nums.empty())
              return res;
          for(int k = 1;k<=nums.size()-1;k++)
          {
              vector<int> p;
              int count = 0,start = 0;
              generate(nums,k,count,start,p);
          }
          res.push_back(nums);
          return res;
    }
};
