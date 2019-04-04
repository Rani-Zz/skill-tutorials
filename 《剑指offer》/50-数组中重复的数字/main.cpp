class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /**
    *给了数组要分析所给数组的特性
    *数组里数组都在0-n-1范围内，说明如果没有重复的话可以通过排序让数字和它的下标一致
    *所以遍历数组如果下标一致继续下一位，如果不一致用它和下标所在数字比较
    *如果相等说明已经存在一个，出现重复
    *如果不等那把它们交换也就是让这个数字回到与它下标一致的位置
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<0)
            return false;
        
        for(int i = 0;i<length;)
        {
            if(numbers[i]==i)
                i++;
            else if(numbers[i]== numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }else{
                swap(numbers[i],numbers[numbers[i]]);
            }
        }
        return false;
        
    }
};