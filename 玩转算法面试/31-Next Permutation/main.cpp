class Solution {
private:
    void reverse(vector<int>& nums,int l,int r)
    {
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++,r--;
        }
        return;
    }
public:
    /**
    *序列全部递减时已经是最大的排列，没有比它更大得了
    *所以还有下一个排列就一定不是全部递减，所以从右到左遍历，找到不是递减的子序列 i开始
    *i以及后面的可以重排
    *找比它大的下一位只要从右边找第一个比i大的数交换,之后翻转i之后的
    */
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
        int i = nums.size()-1;
        while(i>0&&nums[i]<=nums[i-1])
            i--;
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        
        int j = nums.size()-1;
        while(j>0)
        {
            if(nums[j]>nums[i-1])
                break;
            j--;
        }
        swap(nums[i-1],nums[j]);
        reverse(nums,i,nums.size()-1);
        return;
    }
};