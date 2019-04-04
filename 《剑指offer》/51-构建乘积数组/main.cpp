class Solution {
public:
    /**
    *B[i] = A[0]*...*A[n-1]/A[i]
    *���ǲ����ó������������Ǹ����������
    *ÿ��B[i]����ÿ�������Ǻ����������
    *�ȼ��������ǣ��������£�B[i] = B[i-1]*A[i-1] i��1��ʼ
    *�ڼ��������ǣ��������ϣ�tmp = tmp*A[i+1]  B[i] = B[i]*tmp i��n-2��ʼ
    *�����Ϳ�����
    */
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(),1);
        if(A.empty())
            return B;
        for(int i = 1;i<A.size();i++)
              B[i] = B[i-1]*A[i-1];
        
        int tmp = 1;
        for(int i = A.size()-2;i>=0;i--)
        {
            tmp*=A[i+1];
            B[i] = B[i]*tmp;
        }
        
        return B;
    }
};