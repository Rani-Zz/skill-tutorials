class Solution {
public:
    /**
    *Ҫ�ҵ����ֳ��ֵĴ������������ּ��������ֵĴ�����Ҫ�࣬�����һ������Ϊ���
    *��ͬ����+1����ͬ����-1��
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