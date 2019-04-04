class Solution {
private:
    vector<bool> flag;
    bool isfind(char* matrix, int rows, int cols, int i, int j, int k,char* str)
    {
        int index = i*cols+j;
        if(i<0||i>=rows||j<0||j>=cols||matrix[index]!=str[k]||flag[index]!=0)
            return false;
        if(k==strlen(str)-1) return true;
        flag[index] = true;
        if(isfind(matrix,rows,cols,i-1,j,k+1,str)||
           isfind(matrix,rows,cols,i+1,j,k+1,str)||
           isfind(matrix,rows,cols,i,j-1,k+1,str)||
           isfind(matrix,rows,cols,i,j+1,k+1,str)
          )
            return true;
        flag[index] = false;
        return false;
    }
public:
    /**
    *回溯法：
    *没个点都尝试寻找，但是走过的不能再走，所以用flag标记，回溯回来后再还原
    */
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        flag = vector<bool>(strlen(matrix),false);
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
                if(isfind(matrix,rows,cols,i,j,0,str))
                    return true;
        }
        return false;
    }


};