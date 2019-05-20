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
    *һ����ֻ����һ�Σ��Ǿʹӵ�i�����������
    *���� ӦΪ�����а����ظ����������ü���ȥ���ظ����߼�
    *��ϰһЩ����߼������ȸ���������Ȼ��ȥ��ϣ����������ǰһ������ͬ
    *����ǰһ������û���ù�����������Ϊ�������˵��Ҫ���������Ϊ��ͷ����ϣ�����
    *ǰ���Ѿ�����������ˣ�˵������Ѿ������ˣ�
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
