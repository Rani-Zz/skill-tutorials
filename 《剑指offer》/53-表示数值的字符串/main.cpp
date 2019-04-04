class Solution {
public:
    /**
    *主要看符号、e\E、小数点、字符是否合法
    *归纳：
    *e\E：不可以做最后一位，不能出现两次
    *符号：符号出现在开头，后面要有数字；符号出现在中间，前面有一定是e\E
    *小数点：不能出现在e之后，且只能出现1次
    *字符：是不是0-9
    */
    bool isNumeric(char* string)
    {
       bool hasE = false,hasNode = false;
       for(int i = 0;i<strlen(string);i++)
       {
           if(string[i]=='e'||string[i]=='E')
           {
               //已经出现过或者出现在最后一位，不合法
               if(hasE||i==strlen(string)-1) return false;
               hasE = true;
           }else if(string[i]=='+'||string[i]=='-')
           {
               //出现在中间但前面不是e,不合法
               if(i > 0&& (string[i-1]!='e'&&string[i-1]!='E')) return false;
               //出现在开头后面没有了，不合法
               if(i==0&&i==strlen(string)-1) return false; 
           }else if(string[i]=='.')
           {
               //出现在e之后或第二次出现，不合法
               if(hasE||hasNode) return false;
               hasNode = true;
           }else if(string[i]<'0'||string[i]>'9')
           {
               return false;//出现不合法字符
           }
       }
      return true;
    }

};