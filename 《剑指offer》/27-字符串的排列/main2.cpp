class Solution {
private:
    void generate(vector<string> &res,string s,int k)
    {
        if(k==s.size()-1)
        {
            res.push_back(s);
            return;
        }
        for(int i = k;i<s.size();i++)
        {
            if(i!=k&&s[i]==s[k])
                continue;
            swap(s[i],s[k]);
            generate(res,s,k+1);
            swap(s[i],s[k]);
            
        }
        return;
    }
public:
    vector<string> Permutation(string str) {
        if(str.empty())
            return {};
        vector<string> res;
        generate(res,str,0);
        sort(res.begin(),res.end());
        return res;
    }
};
};