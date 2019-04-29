class Solution {
private:
    int operater(int lhs,int rhs,string op)
    {
        if(op=="+")
        {
            return lhs+rhs;
        }
        if(op=="-")
        {
            return lhs-rhs;
        }
        if(op=="*")
        {
            return lhs*rhs;
        }
        if(op=="/")
        {
            return lhs/rhs;
        }
        
        return 0;
    }
public:
    /**
    *用栈
    *遇到数字入栈
    */
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        stack<int> stk;
        for(int i = 0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int rhs = stk.top();
                stk.pop();
                int lhs = stk.top();
                stk.pop();
                int c = operater(lhs,rhs,tokens[i]);
                stk.push(c);
            }else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        if(stk.empty())  return 0;
        return stk.top();
    }
};
