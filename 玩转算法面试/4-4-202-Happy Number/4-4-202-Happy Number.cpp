class Solution {
private:
    int count(int n)
    {
        int tmp = 0;
        while(n!=0)
        {
            int i = n%10;
            tmp+=i*i;
            n/=10;
        }
        
        return tmp;
    }
public:
    /**
    *�����Ϊ1��һֱ���㣬�ѽ����������������������ظ�ʱreturn false
    */
    bool isHappy(int n) {
        unordered_set<int> record;
        while(n!=1)
        {
            if(record.find(n)!=record.end())
                return false;
            record.insert(n);
            n = count(n);
        }
        return true;
    }
};
