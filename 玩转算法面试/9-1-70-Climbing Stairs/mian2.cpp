class Solution {
public:
    /**
    *dp ø’º‰∏¥‘”∂»O£®1£©
    */
    int climbStairs(int n) {
       if(n<2)
           return n;
        
        int pre = 1;
        int cur = 1;
        for(int i = 2;i<=n;i++)
        {
            int tmp = cur;
            cur = tmp+pre; 
            pre = tmp;
        }
        
        return cur;
    }
};
