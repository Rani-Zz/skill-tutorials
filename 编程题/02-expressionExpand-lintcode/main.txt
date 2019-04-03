/**
 * lintcode-575
 * 给出一个表达式S，该表达式只包括数字、字母及方括号这三种元素。该表达式具有如下规则：
 * 数字只会出现在方括号前，它表示方括号内容的重复次数，方括号中的内容可以是普通的字符串，
 * 也可以另一个表达式。请写一段程序，按照上述规则将输入的表达式展开成目标字符串。
 * e3[2[abc]gh]
 * e9[xyz]
*/
class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     * 用栈，遍历字符串入栈，当遇到']'时出栈，保存的另一个字符串dup中，出栈到'[‘时说明需要重复的都找到了
     * 然后再出栈数字，数字都出来后，将dup重复相应的次数,再入栈
     * 都遍历完之后，逐个出栈
     */
    string expressionExpand(string &s) {

        // write your code here
        string res;
        if(s.empty())
            return res;
        stack<char> sk;
        int i = 0;
        while(i<s.size())
        {
            if(s[i]==']')
            {
                string dup;
                while(sk.top()!='[')
                {
                    dup = sk.top()+dup;
                    sk.pop();
                }
                sk.pop();
                string num;
                while(!sk.empty()&&isdigit(sk.top()))
                {
                    num = sk.top()+num;
                    sk.pop();
                }
                int cnt = stoi(num);
                string str;
                while(cnt>0)
                {
                    str+=dup;
                    cnt--;
                }
                for(auto c:str)
                    sk.push(c);
            }else{
                sk.push(s[i]);
            }
            i++;
        }
        
        while(!sk.empty())
        {
            res = sk.top()+res;
            sk.pop();
        }
        return res;
    }
};