class Solution {
private:
    vector<vector<int>> res;
    void generate(int k,int n,int index,vector<int> p)
    {
        if(k==0)
        {
            if(n==0)
                res.push_back(p);
            return;
        }
        
        if(k<0) return;
        
        for(int i = index;i<=9;i++)
        {
            if(n>=i)
            {
                p.push_back(i);
                generate(k-1,n-i,i+1,p);
                p.pop_back();
            }
        }
        
        return;
        
    }
public:
    /**
    *��Ȼ���մ�ʦ�ķ�ʽ����������
    */
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k<1||n<1)
            return res;
        
        vector<int> p;
        generate(k,n,1,p);
        return res;
    }
};
