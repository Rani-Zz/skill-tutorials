#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*
AC67%??
��һ���ַ���ת����һ����������ֵΪ0�������ַ����Ȳ���һ���Ϸ�����ֵ�򷵻�0��
С��ֱ��ȡ�������֡�Ҫ�󣺲���ʹ���ַ���ת�������Ŀ⺯��

������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ 
******************************��ʼд����******************************/
int string2int(string str) {
    if(str.empty())
        return 0;
    int i = 0;
    int n = 0;
    bool flag = true;
    if(str[i]=='+')
    {
    	i++;
	}else if(str[i]=='-')
	{
		flag = false;
		i++;
	}
	
	while(str[i]=='0'||str[i]==' ')
	{
		i++;
	}
	
	while(str[i]!='\0')
	{
		if(str[i]<'0'||str[i]>'9')
		{
			return 0;
		}else if(str[i]=='.')
		{
			break;
		}else
		{
			n*=10;
			n+= str[i]-'0';
		}
		i++;
	}
    
    return flag?n:0-n;
}
/******************************����д����******************************/


int main() {
    int res;

    string _str;
    getline(cin, _str);
    
    res = string2int(_str);
    cout << res << endl;
    
    return 0;

}
