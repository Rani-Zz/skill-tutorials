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
        //��䲻дҲ���ԣ���Ϊ��д�����ѭ��Ҳ���жϲ�ִ��
        if(index>=candidates.size())
            return;
        for(int i = index;i<candidates.size();i++)
        {
            //�����ֽ����˼�֦����
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
    *��ϵ�ʱ�������߾Ͳ������ظ�
    *����ÿ�����ֿ����ظ����������˵�i�������ٴӵ�i������ʼ������
    *�������� 
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;
        vector<int> p;
        generate(candidates,target,0,p);
        return res;
    }
};
