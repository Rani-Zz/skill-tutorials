class Solution {
public:
    /**
    *递增排序，所以用对撞指针
    */
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int l = 0,r = array.size()-1;
        int tmp = 0;
        int minMul = INT_MAX;
        while(l<r)
        {
            tmp = array[l]+array[r];
            if(tmp>sum)
                r--;
            else if(tmp<sum)
                l++;
            else{
                if(array[l]*array[r]<minMul)
                {
                    minMul = array[l]*array[r];
                    if(!res.empty())
                    {
                        res.pop_back();
                        res.pop_back();
                    }
                    res.push_back(array[l]);
                    res.push_back(array[r]);
                }
                l++;
                r--;
            }
        }
        return res;
    }
};