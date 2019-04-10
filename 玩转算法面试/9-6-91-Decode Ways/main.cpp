class Solution {
public:
    /**
    *memo[i]：表示长度为i的string有几种解码方式
    *跟跳台阶的思路一样，可以一次一个，也可以一次两个
    *但是需要判断是否可以这样做，1-9可以走一个，两个10-26可以
    *memo[i] = memo[i-1]+memo[i-2]
    */
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        int n =s.size();
        vector<int> memo(n+1,0);
        memo[0] = 1;
        memo[1] = s[0]>='1'&&s[0]<='9' ? 1:0;
        for(int i = 2;i<=n;i++)
        {
            if(s[i-1]>='1'&&s[i-1]<='9')
                memo[i]+=memo[i-1];
            if(stoi(s.substr(i-2,2))>=10&&stoi(s.substr(i-2,2))<=26)
                memo[i]+=memo[i-2];
        }
        
        return memo[n];
    }
};
