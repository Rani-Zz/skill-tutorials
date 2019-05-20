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
        //这句不写也可以，因为不写下面的循环也会判断不执行
        if(index>=candidates.size())
            return;
        for(int i = index;i<candidates.size();i++)
        {
            //这里又进行了剪枝操作
            if(target>=candidates[i])
            {
                p.push_back(candidates[i]);
                generate(candidates,target-candidates[i],i,p);
                p.pop_back();
            }
        }
    }
public:
    /**
    *组合的时候不往回走就不会有重复
    *但是每个数字可以重复，所以用了第i个数后再从第i个数开始往后尝试
    *绝妙至极 
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        vector<int> p;
        generate(candidates,target,0,p);
        return res;
    }
};
