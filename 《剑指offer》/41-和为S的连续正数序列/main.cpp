class Solution {
public:
    /**
    *»¬¶¯´°¿Ú
    */
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>>  res;
        int l = 1,r = 1;
        int tmp = 1;
        while(l<=r)
        {
            r++;
            tmp+=r;
             while(tmp>sum)
            {
                tmp-=l;
                l++;
            }
            if(tmp==sum&&l!=r)
            {
                vector<int> p;
                for(int i = l;i<=r;i++)
                    p.push_back(i);
                res.push_back(p);
            }
           
           
        }
        return res;
    }
};