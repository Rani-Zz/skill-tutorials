class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> candidates,int target,int start,int sum,vector<int> p)
    {
        if(sum==target)
        {
            if(find(res.begin(),res.end(),p)==res.end())
                res.push_back(p);
            return;
        }
        if(sum>target)
            return;        
        if(start == candidates.size())
            return;

        for(int i = start;i<candidates.size();i++)
        {
            p.push_back(candidates[i]);
            sum+=candidates[i];
            generate(candidates,target,i+1,sum,p);
            p.pop_back();
            sum-=candidates[i];
        }
        return;
        
    }
public:
    /**
    每个数字只可使用一次
    */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        sort(candidates.begin(),candidates.end());
        vector<int> p;
        int sum = 0,start = 0;
        generate(candidates,target,start,sum,p);
        
        return res;
    }
};
