class Solution {
public:
    /**
    *用栈
    *遇到ls入栈 遇到rs出栈判断是否是相应的ls 不是false
    *最后判断是否为空 不空false
    */
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> stk;
        for(int i = 0;i<s.size();i++)
        {
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if(stk.empty())
                    return false;
                    if(stk.top()!='(')
                        return false;
                    else
                        stk.pop();
                    break;
                case']':
                    if(stk.empty())
                    return false;
                    if(stk.top()!='[')
                        return false;
                    else
                        stk.pop();
                    break;
                case'}':
                    if(stk.empty())
                    return false;
                    if(stk.top()!='{')
                        return false;
                    else
                        stk.pop();
                    break;
            }   
        }
        
        return stk.empty();
    }
};
