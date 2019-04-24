class Solution {
public:
    /**
    *1)如果两个都为空 为true
    *2)如果字符串不空，模式为空，false（反过来就不一定了，模式如果为*那也是匹配的）
    *3)字符串空模式不空，匹配成功的话就是模式为‘.’,只有这一种情况
    *  都不为空，开始匹配第一个字符，但是第二个字符是不是'*'会影响第一个字符的匹配
    *  所以分两种情况：
    *  a)第二个字符不为‘*’，则第一个字符相同或是模式为‘.’且str不空则匹配成功否则失败，匹配成功继续下一位
    *  b)第二个字符为‘*’，因为‘*’前面的字符可以出现0次或者多次，所以再分情况：
                       i)匹配0次，也就是当前不等，那么模式跳过‘*’即后移两位继续匹配，str不变
                       ii)只匹配1次，也就是当前相等，那依旧跳过‘*’
                          或者匹配多次，str后移1位，模式不变
    *思路还待补充
    *因为*str == *pattern时有两种情况：匹配0个字符和匹配一次及以上，如ab和a*ab就只需要匹配零个。*str ！= *pattern只有一种情况，就只能匹配0个字符
    */
    bool match(char* str, char* pattern)
    {
        if(*str=='\0'&&*pattern=='\0')
            return true;
        if(*str!='\0'&&*pattern=='\0')
            return false;
        if(*(pattern+1)!='*')
        {
            if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
                return match(str+1,pattern+1);
            else
                return false;
        }else{
            if(*str==*pattern||(*str != '\0' && *pattern == '.'))
                return match(str,pattern+2)||match(str+1,pattern);
            else
                return match(str,pattern+2);
        }
        
    }
};
