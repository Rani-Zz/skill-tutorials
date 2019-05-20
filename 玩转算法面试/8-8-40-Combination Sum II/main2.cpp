class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> candidates,int target,int index,vector<int> p)
    {
        if(target==0)
        {
            res.push_back(p);
            return;
        }
        
        for(int i = index;i<candidates.size();i++)
        {
            //i>index
            if(i>index&&candidates[i]==candidates[i-1])
                continue;
            if(target>=candidates[i])
            {
                p.push_back(candidates[i]);
                generate(candidates,target-candidates[i],i+1,p);
                p.pop_back();     
            }
        }
        
        return;
    }
public:
    /**
    *一个数只能用一次，那就从第i个数往后组合
    *另外 应为数组中包含重复的数，还得加上去掉重复的逻辑
    *复习一些这个逻辑啊，先给数组排序，然后去组合，如果遇到跟前一个数相同
    *并且前一个数还没有用过就跳过（因为这种情况说明要以这个数字为开头做组合，但是
    *前面已经有这个数字了，说明组合已经做过了）
    */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        sort(candidates.begin(),candidates.end());
        vector<int> p;
        generate(candidates,target,0,p);
        return res;
    }
};
