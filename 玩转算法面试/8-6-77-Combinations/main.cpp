class Solution {
private: 
    vector<vector<int>> res;
    void generate(int n,int k,int start,vector<int>& c)
    {
        if(c.size()==k)
        {
            res.push_back(c);
            return ;
        }
        //剪枝：在[i...n]里面至少要有k-c.size()个元素，才有必要继续循环
        //所以n-i+1>=k-c.size() 即i<=n-(k-c.size())+1
        //这样修改后节省了很多时间
        for(int i = start;i<=n-(k-c.size())+1;i++)
        {
            c.push_back(i);
            generate(n,k,i+1,c);
            c.pop_back();
        }
       return;
    }
public:
    /**
    回溯：排列问题
    */
    vector<vector<int>> combine(int n, int k) {
        if(n<=0||k<=0||k>n) 
            return res;
        
        vector<int> c;
        generate(n,k,1,c);
        return res;
    }
};
