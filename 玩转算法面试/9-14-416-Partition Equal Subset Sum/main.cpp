class Solution {
private:
    vector<vector<int>> memo;
     // ʹ��nums[0...index], �Ƿ������ȫ���һ������Ϊsum�ı���
    bool tryPartition(const vector<int> &nums, int index, int sum){
        if(sum==0)
            return true;
        
        if(sum < 0 || index < 0)
            return false;
        
        if(memo[index][sum]!=-1)
            return memo[index][sum]==1;
        
        memo[index][sum] = tryPartition(nums,index-1,sum)||
                           tryPartition(nums,index-1,sum-nums[index])? 1:0;
        
        return memo[index][sum]==1;
    }
    
public:
    /**
    *�������⣺�����ܹ����һ������Ϊsum/2�ı���
    *memo[i][c] ��ʾʹ������Ϊ[0...i]����ЩԪ��,�Ƿ������ȫ���һ������Ϊc�ı���
    */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums)
            sum+=i;
        
        if(sum%2)
            return false;
        for(int i = 0;i<nums.size();i++)
        {
            memo.push_back(vector<int>(sum/2+1,-1));
        }
        return tryPartition(nums,nums.size()-1,sum/2);
    }
};
