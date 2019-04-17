class Solution {
public:
    /**
    *先统计空格的数量
    *然后计算总共的长度
    *用两个指针，从后向前拷贝
    */
	void replaceSpace(char *str,int length) {
        if(str==""||length<=0)
            return;
        int count =0;
        int i = 0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
                count++;
            i++;
        }
        int newLength = length+count*2;
        int p = length,q = newLength;
        for(p,q;q>p;)
        {
            if(str[p]!=' ')
            {
                str[q--] = str[p--];
            }else{
                str[q--] = '0';
                str[q--] = '2';
                str[q--] = '%';
                p--;
            }
        }
        return ;
	}
};