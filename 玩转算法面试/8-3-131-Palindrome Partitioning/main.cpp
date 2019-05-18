class Solution {
private:
    vector<vector<string>> res;
    void generate(string s,int index,vector<string> p)
    {
        if(index==s.size())
        {
            res.push_back(p);
            return;
        }
        
        for(int i = index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                p.push_back(s.substr(index,i-index+1));
                generate(s,i+1,p);
                p.pop_back();
            }
        }
        return;
    }
    bool isPalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;j--;
            }else return false;
        }
        
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return res;
        vector<string> p;
        generate(s,0,p);
        return res;
    }
};
