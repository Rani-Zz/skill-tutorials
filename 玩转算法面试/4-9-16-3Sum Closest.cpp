class Solution {
public:
    /**
    *跟3Sum一样
    还是对撞指针，找最接近的
    *需要一个变量记录与目标数的差
    *注意跳过重复可以提升很多还有sum为target直接返回
    */
    int threeSumClosest(vector<int>& nums, int target) {
        int gap = INT_MAX;
        int res =  0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==target) return sum;
                if(abs(target-sum)<gap)
                {
                    res = sum;
                    gap = abs(target-sum);
                }
                if(sum>target) r--;
                else l++;
            }
        }
        return res;
    }
};