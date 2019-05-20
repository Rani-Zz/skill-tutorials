class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> candidates,int target,int sum,vector<int> p)
    {
        if(sum == target)
        { 
            sort(p.begin(),p.end());
            if(find(res.begin(),res.end(),p)==res.end())
                  res.push_back(p);
            return;
        }
        
        if(sum>target)
            return;
        
        for(int i = 0;i<candidates.size();i++){
            p.push_back(candidates[i]);
            sum+=candidates[i];
            generate(candidates,target,sum,p);
            p.pop_back();
            sum-=candidates[i];
        }
        return ;
    }
public:
    /**
    列举所有情况，返回等于target的组合
    这样做应该会及其慢，不知道怎么剪枝
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        vector<int> p;
        generate(candidates,target,0,p);
        
        return res;
    }
};
