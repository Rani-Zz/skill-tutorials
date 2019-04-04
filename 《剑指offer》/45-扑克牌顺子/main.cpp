bool comp(const int &a,const int &b)
{
    return a<b;
}
class Solution {
public:
    /**
    *看空缺的数字能不能用0补齐，也就是空缺的个数大于0的个数的话就不能为顺子
    *先对数组排序，统计0的个数，再求相邻数间空缺数
    */
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        sort(numbers.begin(),numbers.end(),comp);
        int zeroCount = 0;
        for(int i = 0;i<numbers.size()&&numbers[i]==0;i++)
            zeroCount++;
        int i = zeroCount;
        int j = i+1;
        int numbersGap = 0;
        while(j<numbers.size())
        {
            if(numbers[j]==numbers[i])
                return false;
            numbersGap+=numbers[j]-numbers[i]-1;
            i++;j++;
        }
        return numbersGap>zeroCount? false:true;
        
    }
};