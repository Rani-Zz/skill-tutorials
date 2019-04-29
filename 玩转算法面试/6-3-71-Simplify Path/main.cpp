class Solution {
public:
    /**
    *��/�ָ�
    *���Էָ���м������ /a/./..///b
    *��ĸ ��ջ
    *. ����
    *.. ��ջ
    *���б�ܼ�ʲô��û��Ҳ�Ǽ���
    *��ջ��ʱ���ַ���ǰ����б�ܾͿ�����
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
