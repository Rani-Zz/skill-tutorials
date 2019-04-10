class Solution {
public:
    /**
    *先考虑特殊情况，都空为true,有一个为空为false
    *匹配成功的条件:相同的字符出现的次数一致，且位置也一致
    *str有空格，所以用字符读入，每次读入一个，字符没有读完但是str已经结束了false
    *某个字符不匹配 false
    *用unordered_map存放，因为必须要保证位置也一致，所以map里面存放的不能只是出现的次数
    *否则“aba” "dag cat cat"出错
    *神仙逻辑存放下标i+1可以解决这个问题
    */
    bool wordPattern(string pattern, string str) {
        if(pattern.empty()&&str.empty())
            return true;
        if(pattern.empty()||str.empty())
            return false;
        int i = 0;
        unordered_map<char,int> pmap;
        unordered_map<string,int> smap;
        istringstream in(str);
        string buf;
        for(i;in>>buf;i++)
        {
            if(i==pattern.size()||pmap[pattern[i]]!=smap[buf])
                return false;
            pmap[pattern[i]] = smap[buf] = i+1;
        }
        
        return i==pattern.size();
    }
};