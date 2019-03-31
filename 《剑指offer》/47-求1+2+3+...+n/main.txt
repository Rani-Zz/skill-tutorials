class Solution {
public:
    /**
    *不能用循环，就是让递归，但是也不能用条件判断
    *这个方法真的绝了 逻辑与
    */
    int Sum_Solution(int n) {
        int res = n;
        res&&(res+=Sum_Solution(n-1));
        return res;
    }
};