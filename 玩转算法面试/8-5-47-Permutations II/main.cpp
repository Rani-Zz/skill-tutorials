class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void generate(vector<int> nums,int index,vector<int>& p)
    {
        if(index == nums.size())
        {
           if(find(res.begin(),res.end(),p)==res.end()) res.push_back(p);
            return ;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(!used[i])
            {
                p.push_back(nums[i]);
                used[i] = true;
                generate(nums,index+1,p);
                p.pop_back();
                used[i] = false;
            }
        }
    }
public:
    /**
    ���� 46�Ľⷨ�����nums�д�����ͬ�����֣���ô���Ľ���оͻ����ظ��ģ�
    �Ǳ����ʱ��������ھͲ�����,�����ʱ��ÿ�ζ�Ҫ����һ�飬�����������
    */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return res;
        
        vector<int> p;
        used = vector<bool>(nums.size(),false);
        generate(nums,0,p);
        
        return res;
    }
};
