class Solution {
public:
    /**
    *��ջ
    *����ls��ջ ����rs��ջ�ж��Ƿ�����Ӧ��ls ����false
    *����ж��Ƿ�Ϊ�� ����false
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
