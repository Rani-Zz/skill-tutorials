class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int row = matrix.size();
        int column = matrix[0].size();
        if(row==0&&column==0)
            return res;
        //一圈上下左右要遍历的行列
        int left = 0,right = column-1,top = 0,btm = row-1;
        while(left<=right&&top<=btm)
        {
            for(int i = left;i<=right;i++)
                res.push_back(matrix[top][i]);
            if(top<btm)
            {
                for(int i = top+1;i<=btm;i++)
                    res.push_back(matrix[i][right]);
            }
            if(top<btm&&left<right)
            {
                for(int i = right-1;i>=left;i--)
                    res.push_back(matrix[btm][i]);
            }
            if(top+1<btm&&left<right)
            {
                for(int i = btm-1;i>top;i--)
                    res.push_back(matrix[i][left]);
            }
            left++,right--,top++,btm--;
        }
        return res;
    }
};