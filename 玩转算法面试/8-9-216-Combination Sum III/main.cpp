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
        int limit = n>=9?9:n;//���������𵽼�֦�����ð�
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
    ����в��ɰ����ظ�
    һ����ÿ����ֻ����һ��
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
