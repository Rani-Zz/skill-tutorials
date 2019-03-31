class Solution {
public:
    /**
    *考虑str为空
    *考虑str前面有空格符
    *考虑第一位为+、-号
    *考虑中间出现字母符号为不合法
    */
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        bool flag = true;
        int i = 0;
        //滤掉前面的空格
        while(str[i]==' '){
            i++;
        }
        char c  = str[i];
        if(c=='-')
        {
            flag = false;
            i++;
        }   
        if(c=='+')
        {
            i++;
        }
        int num = 0;
        for(int j = i;j<str.size();j++)
        {
            if(str[j]>='0'&&str[j]<='9')
            {
                num *=10;
                num+=str[j]-'0';
            }else
                return 0;
        }
        num = flag? num :(0-num);
        
        return num;
    }
};