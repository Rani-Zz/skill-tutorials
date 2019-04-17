class Solution {
public:
    /**
    *��̬�滮
    *dp[i]��ʾ�Ե�i����ĸ��β�������
    *Ȼ��ѡ���
    *dp[i] = max(dp[i-1]+a[i],a[i])
    *�ռ临�Ӷȿ��Խ���O��1��
    *ֻ����ǰ��Ľ�� ����
    *�����ӽṹ��ÿһ����ȡ���ֵ
    */
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        if(n==0) return 0;
        if(n==1) return array[0];
        if(n==2) return max(array[0],array[1]);
        
        int cur = array[0];
        int res = cur;
        for(int i = 1;i<n;i++)
        {
            cur = max(cur+array[i],array[i]);
            res = max(res,cur);
        }
        return res;
    }
};
