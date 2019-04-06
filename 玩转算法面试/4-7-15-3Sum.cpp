class Solution {
public:
    /**
    *先排序，确定一个数后，按照对撞指针找two sum
    *解决重复的问题，跳过相同的数，因为用stl的方法会超时
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();)
        {
            int a = nums[i];
            int target = 0 - a;
            int l = i+1,r = nums.size()-1;
            while(l<r)
            {
                int sum = nums[l]+nums[r];
                if(sum>target)
                    r--;
                else if(sum<target)
                    l++;
                else
                {
                    int b = nums[l];
                    int c = nums[r];
                    res.push_back({a,b,c});
                    while(l<r&&nums[l]==b) l++;
                    while(l<r&&nums[r]==c) r--;
                }
            }
            while(i<nums.size()&&nums[i]==a) i++;
        }
        
        return res;
    }
};