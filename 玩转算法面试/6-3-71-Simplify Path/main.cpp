class Solution {
public:
    /**
    *用/分割
    *所以分割后有几种情况 /a/./..///b
    *字母 入栈
    *. 不动
    *.. 出栈
    *另个斜杠间什么都没有也是继续
    *出栈的时候字符串前加上斜杠就可以了
    */
    string simplifyPath(string path) {
        string res,buf;
        stringstream ss(path);
        stack<string> stk;
        while(getline(ss,buf,'/'))
        {
            if(buf=="."||buf=="") continue;
            if(buf==".."&&!stk.empty()) stk.pop();
            else if(buf!="..") stk.push(buf);
        }
        
        while(!stk.empty())
        {
            res = "/"+stk.top()+res;
            stk.pop();
        }
        
        return res.empty()?"/":res;
    }
};
