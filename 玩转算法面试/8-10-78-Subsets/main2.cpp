class Solution {
private:
    vector<vector<int>> res;
    void generate(vector<int> nums,int k,int index,vector<int> p)
    {
        if(k==0)
        {
            res.push_back(p);
            return;
        }
        
        if(k<0) return;
        
        for(int i = index;i<nums.size();i++)
        {
            p.push_back(nums[i]);
            generate(nums,k-1,i+1,p);
            p.pop_back();
        }
        
        return;
    }
public:
    /**
    *ǰ�������չ��֮ǰ�޶�k����
    *����kΪ[0,n-1]
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return res;
        for(int i = 1;i<nums.size();i++)
        {
            vector<int> p;
            generate(nums,i,0,p);
        }
        //���Ҫ���ǿռ���ȫ��
        res.push_back(vector<int>{});
        res.push_back(nums);
        
        return res;
    }
};
