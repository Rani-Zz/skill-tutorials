class Solution {
public:
    /**
    *B[i] = A[0]*...*A[n-1]/A[i]
    *但是不能用除法，所以想那个矩阵的样子
    *每个B[i]都是每行下三角和上三角相乘
    *先计算下三角，从上往下，B[i] = B[i-1]*A[i-1] i从1开始
    *在计算上三角，从下往上，tmp = tmp*A[i+1]  B[i] = B[i]*tmp i从n-2开始
    *这样就可以了
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