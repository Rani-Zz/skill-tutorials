class Solution {
private:
    vector<vector<int>> res;
    void generate(int k,int n,int count,int start,int sum,vector<int> p)
    {
        if(sum==n&&count==k)
        {
            res.push_back(p);
        }
        if(sum>n||count>k)
            return ;
        int limit = n>=9?9:n;//这样可以起到剪枝的作用吧
        for(int i = start;i<=limit;i++)
        {
            p.push_back(i);
            sum+=i;
            count++;
            generate(k,n,count,i+1,sum,p);
            p.pop_back();
            sum-=i;
            count--;
        }
        
        return;
    }
public:
    /**
    结果中不可包含重复
    一组中每个数只能用一次
    */
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k<=0||n<=0)
            return res;
        vector<int> p;
        int count = 0,start = 1,sum = 0;
        generate(k,n,count,start,sum,p);
        return res;
    }
};
