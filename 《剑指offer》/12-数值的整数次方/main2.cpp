class Solution {
 private:
    bool equals(double num1,double num2)
    {
        if(abs(num1-num2)<1e-6)
            return true;
        return false;
    }
public:
    /**
    *����������� ex<0 base����Ϊ0 -ex ==0 return 1
    *ex����ż�� �����ö�����λ�ж�
    */
    double Power(double base, int exponent) {
        int n = 0;
        if(exponent>0)
            n = exponent;
        else if(exponent<0)
        {
            if(equals(base,0.0))
                return base;
            n = -exponent;
        }else 
        {
            if(equals(base,0.0)) return base; 
            return 1;
        }   
        
        double res = 1,curr = base;
        while(n!=0)
        {
            if((n&1)==1)
                res*=curr;
            curr*=curr;
            n = n>>1;
        }
        return exponent>0? res : 1/res;
    }
};
