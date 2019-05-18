class Solution {
private:
    vector<string> res;
    const string letter[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void generate(string digits,int index,string s)
    {
        if(index==digits.size())
        {
            res.push_back(s);
            return;
        }
        
        char c = digits[index];
        string tmp = letter[c-'0'];
        for(int i = 0;i<tmp.size();i++)
        {
            s+=tmp[i];
            generate(digits,index+1,s);
            s.pop_back();
        }
        
        return;
    }
public:
    /**
    *»ØËÝ·¨
    */
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        generate(digits,0,"");
        
        return res;
    }
};
