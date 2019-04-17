class Solution {
public:
    /**
    *从左上角开始遍历
    *<i++ >j--
    */
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int i = 0,j = array[0].size()-1;
        while(i<array.size()&&j>=0)
        {
            if(array[i][j]==target)
            {
                return true;
            } 
            else if(array[i][j]<target)
                i++;
            else 
                j--;
        }
        return false;
    }
};