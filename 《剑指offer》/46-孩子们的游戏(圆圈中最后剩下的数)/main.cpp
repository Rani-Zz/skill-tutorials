class Solution {
public:
    /**
    *ģ�⻷ countͳ��ʣ�µ����ֵĸ�����stepͳ���߹��Ĳ�����stepΪmʱɾ����
    *��������Ϊ-1��ʾ��ɾ������ʱ����
    */
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        vector<int> nums;
        for(int i = 0;i<n;i++)
            nums.push_back(i);
        int count = n,step = 0,i = -1;
        while(count>0)
        {
            i++;
            if(i>=n) i = 0;
            if(nums[i]==-1) continue;
            step++;
            if(step==m)
            {
                nums[i] = -1;
                step = 0;
                count--;
            }
        }
        return i;
    }
};