class Solution {
public:
    /**
    *����strΪ��
    *����strǰ���пո��
    *���ǵ�һλΪ+��-��
    *�����м������ĸ����Ϊ���Ϸ�
    */
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        bool flag = true;
        int i = 0;
        //�˵�ǰ��Ŀո�
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