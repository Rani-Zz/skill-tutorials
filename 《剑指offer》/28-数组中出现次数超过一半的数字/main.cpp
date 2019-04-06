class Solution {
public:
    /**
    *要找的数字出现的次数比其他数字加起来出现的次数还要多，假设第一个数字为结果
    *相同次数+1，不同次数-1，
    */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int times = 1;
        int val = numbers[0];
        for(int i = 1;i<numbers.size();i++)
        {
            if(times==0)
            {
                times = 1;
                val = numbers[i];
            }else if(numbers[i]==val)
                times++;
            else
                times--;
        }
        int count = 0;
        for(int i = 0;i<numbers.size();i++)
        {
            if(numbers[i]==val)
                count++;
        }
        
        return count>numbers.size()/2? val:0;
    }
};