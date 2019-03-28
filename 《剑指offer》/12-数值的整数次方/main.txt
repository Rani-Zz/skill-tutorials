class Solution {
private:
    bool equal(double num1,double num2)
    {
        if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
            return true;
        else 
            return false;
    }
    double powerWithexponent(double base,int exponent)
    {
        if(exponent==0)
            return 1.0;
        if(exponent==1)
            return base;
        double result = powerWithexponent(base,exponent>>1);//用右移代替除以2效率更高
        result*=result;
        if(exponent&0x1==1) //用位与运算代替%效率更高
            result*=base;
        return result;
        
        return result;
    }
public:
    /**
    *exponent<0的情况
    *错误处理：输入是否合法 base为0，exponent<0 错误处理方式的优缺点 
    *返回值：返回类型为double 无法判断是输入有误还是 计算结果为 0.0；
    *全局变量：不影响正常情况下的返回，但是要记得check全局变量
    *抛出异常：有些语言不支持比如C，打乱程序的执行顺序，影响性能
    *更优的方法：
    */
    bool g_InvalidInput = false;
    double Power(double base, int exponent) {
        if(equal(base,0.0)&&exponent<0)
        {
            g_InvalidInput = true;
            return 0.0;
        }
        int absexponent = abs(exponent);
        double result = powerWithexponent(base,absexponent);
        if(exponent<0)
            result = 1.0/result;
        return result;
    }
};