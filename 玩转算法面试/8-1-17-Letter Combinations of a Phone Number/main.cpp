class Solution {
private:
            vector<string> res;
            const string lettermap[10] = {
                " ",
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
    void combineLetter(string digits,int index,string s)
    {
        if(index == digits.size())
        {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        string letterstring = lettermap[c-'0'];
        
        for(int i = 0;i<letterstring.size();i++)
        {
            combineLetter(digits,index+1,s+letterstring[i]);
        }
    }

public:
    /**
    一位一位的确定字母
    */
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        
        combineLetter(digits,0,"");
        return res;
    }
};
