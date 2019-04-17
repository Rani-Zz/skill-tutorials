class Solution {
public:
     /**
     *数组规律 两部分都是递增
     *那么只要找到一个数组比前一个数字小他就是最小的元素
     *时间复杂度O(n)
     */
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        if(rotateArray.size()==1)
            return rotateArray[0];
        
        for(int i = 1;i<rotateArray.size();i++)
        {
            if(rotateArray[i]<rotateArray[i-1])
                return rotateArray[i];
        }
        return 0;
    }
};