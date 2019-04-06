class Solution {
public:
    /**
    *背包问题
    *保证每一步都找到一个较大的值，再把这个较大的值和结果对比，记录较大的作为结果
    *使用动态规划
    *F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
    *F（i）=max（F（i-1）+array[i] ， array[i]） 
    *res：所有子数组的和的最大值
    *res=max（res，F（i））
    */
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = array[0];
        int res = array[0];
        for(int i = 1;i<array.size();i++)
        {
            sum = max(sum+array[i],array[i]);//包含array[i]的最大和
            res = max(res,sum);
        }
        return res;
    }
};