class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generate(vector<int> nums,int k,vector<int> p)
    {
        if(k==nums.size())
        {
            res.push_back(p);
            return ;
        }
        for(int i = 0 ;i<nums.size();i++)
        {
            if(!used[i])
            {
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1])
                    continue;
                
                p.push_back(nums[i]);
                used[i] = true;
                generate(nums,k+1,p);
                p.pop_back();
                used[i] = false;
            }
        }
        
        return;
    }
public:
    /**
    *���ظ����֣��Ȱ�nums������ϵ�ʱ�������ظ�
    *1 1 
    *�������ڶ���1ʱ�����һ��1�Ѿ�����������ǵڶ���1�������ڳ���
    *�����������У���continue�����������˵��Ҫ���������Ϊ��ͷ����ϣ���������Ѿ��ڶ��γ����ˣ���������Ϊ��ͷ������Ѿ�����һ���ˣ�����Ҫ���ظ�����������
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return res;
        used = vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        vector<int> p;
        generate(nums,0,p);
        return res;
    }
};
