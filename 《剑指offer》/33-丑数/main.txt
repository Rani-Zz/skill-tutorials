class Solution {
private:
    int min3(int a,int b,int c)
    {
        return min(min(a,b),c);
    }
public:
    /**
    *从1开始后面的丑数肯定都是前面丑数的2倍、3倍或5倍
    *用一个数组按从小到大的顺序保存这些丑数
    *怎么会越界nums(index,0)
    */
    int GetUglyNumber_Solution(int index) {
        if(index<0) return 0;
        vector<int> nums(index+1,0);
        nums[0] = 1;
        int nextIndex = 1;
        int ugly2 = 0 ,ugly3 = 0, ugly5 = 0;
        while(nextIndex<index)
        {
            int ugly = min3(nums[ugly2]*2,nums[ugly3]*3,nums[ugly5]*5);
            nums[nextIndex] = ugly;
            while(nums[ugly2]*2<=ugly)
                ugly2++;
            while(nums[ugly3]*3<=ugly)
                ugly3++;
            while(nums[ugly5]*5<=ugly)
                ugly5++;
            nextIndex++;
        }
        return nums[index-1];
    }
};