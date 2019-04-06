class Solution {
private:
    int indexOf1(int tmp)
    {
        int index = 0;
        while((tmp&1)==0)
        {
            index++;
            tmp = tmp>>1;
        }
        return index;
    }
    bool isBit1(int num,int k)
    {
        num = num>>k;
        return (num&1);
    }
public:
    /**
    *因为有两个数字出现了1次，所以整个数组异或之后结果的二进制表示至少有1位是1
    *按照二进制位为1的规则将数组分开，分别异或，就可以将两个数字分到不同的数组中
    *得到的结果就是
    *&运算符的优先级，要括起来
    */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)
            return;
        int tmp = 0;
        for(auto i:data)
            tmp^=i;
        int index = indexOf1(tmp);
        *num1 = 0;
        *num2 = 0;
        for(int i = 0;i<data.size();i++)
        {
            if(isBit1(data[i],index))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
};