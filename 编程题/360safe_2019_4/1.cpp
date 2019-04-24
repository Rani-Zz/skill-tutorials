#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*
AC67%??
将一个字符串转换成一个整数，数值为0或者是字符串等不是一个合法的数值则返回0，
小数直接取整数部分。要求：不能使用字符串转换整数的库函数

请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
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
/******************************结束写代码******************************/


int main() {
    int res;

    string _str;
    getline(cin, _str);
    
    res = string2int(_str);
    cout << res << endl;
    
    return 0;

}
