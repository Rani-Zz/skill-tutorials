class Solution {
private:
    vector<bool> flag;
    int move(int limit,int r,int c,int i,int j)
    {
        if(i<0||i>=r||j<0||j>=c||flag[i*c+j]||bit(i)+bit(j)>limit) return 0;
        flag[i*c+j] = true;
        return 1+move(limit,r,c,i-1,j)+
               move(limit,r,c,i+1,j)+
               move(limit,r,c,i,j-1)+
               move(limit,r,c,i,j+1);
               
    }
    int bit(int n)
    {
        int sum = 0;
        while(n!=0)
        {
            sum+=n%10;
            n = n/10;
        }
        return sum;
    }
public:
    /**
    *递归所有情况
    */
    int movingCount(int threshold, int rows, int cols)
    {
        flag = vector<bool>(rows*cols,false);
        return move(threshold,rows,cols,0,0);
    }
};