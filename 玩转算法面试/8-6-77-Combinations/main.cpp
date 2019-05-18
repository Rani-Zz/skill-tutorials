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
        //��֦����[i...n]��������Ҫ��k-c.size()��Ԫ�أ����б�Ҫ����ѭ��
        //����n-i+1>=k-c.size() ��i<=n-(k-c.size())+1
        //�����޸ĺ��ʡ�˺ܶ�ʱ��
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
    ���ݣ���������
    */
    vector<vector<int>> combine(int n, int k) {
        if(n<=0||k<=0||k>n) 
            return res;
        
        vector<int> c;
        generate(n,k,1,c);
        return res;
    }
};
