class Solution {
private:
    vector<string> res;
    vector<bool> used;
    void generate(string str,int index,string p)
    {
        if(index==str.size())
        {
            res.push_back(p);
            return;
        }
        for(int i = 0;i<str.size();i++)
        {
            if(!used[i])
            {
                used[i] = true;
                p+=str[i];
                generate(str,index+1,p);
                p.pop_back();
                used[i] = false;;
            }
        }
    }
public:
    /**
    *���ַ�ʽ�����ڲ����ظ�Ԫ�ص�
    *���Բ������ŵĽⷨ
    */
    vector<string> Permutation(string str) {
        if(str.empty())
            return res;
        used = vector<bool>(str.size(),false);
        string p;
        generate(str,0,p);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};