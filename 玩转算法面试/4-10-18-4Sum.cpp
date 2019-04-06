class Solution {
public:
    /**
    *先排序
    *a,b跳过重复跟3Sum的方法一样
    *所以还是用对撞指针
    *主要是跳过重复以及不可能的结果，提升效率
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        

        for(int i = 0;i<n-3;i++)
        {   
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;
            for(int j = i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int l = j+1,r = n-1;
                
                while(l<r)
                {
                    int sum=nums[l]+nums[r]+nums[i]+nums[j];
                     if(sum<target) l++;
                    else if(sum>target) r--;
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        do{l++;}while(nums[l]==nums[l-1]&&l<r);
                        do{r--;}while(nums[r]==nums[r+1]&&l<r);
                    }
                    
                }
            }
        }
               
        return res;
    }
};