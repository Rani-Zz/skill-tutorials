class Solution {
public:
    /**
    *��ͳ�ƿո������
    *Ȼ������ܹ��ĳ���
    *������ָ�룬�Ӻ���ǰ����
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